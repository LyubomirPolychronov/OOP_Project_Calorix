#include "Trainee.h"

Trainee::Trainee(const std::string& name, const std::string& pass, const UserProfile& profile) : User(name,pass,profile)
{
}

void Trainee::login(const std::string& username, const std::string& password)
{
	std::cout << "Welcome back " << this->getUsername() << "\n";
}

void Trainee::logout()
{
	std::cout << "User " << this->getUsername() << " logged out successfully\n";
}

void Trainee::help() const
{
	std::cout << "--- Trainee Available Commands ---\n"
		<< "1. set-goals <goal-type> <target-value> <deadline>\n"
		<< "2. log-food <food-name> <quantity_grams>\n"
		<< "3. log-exercise <exercise-name> <duration_minutes>\n"
		<< "4. view-daily-summary\n"
		<< "5. view-progress\n"
		<< "6. calculate-bmi\n"
		<< "7. calculate-bmr\n"
		<< "8. generate-workout-plan <duration_minutes>\n"
		<< "9. add-to-favorites <exercise-name>\n"
		<< "10. view-favorites\n"
		<< "11. logout\n"
		<< "----------------------------------\n";
}

void Trainee::setGoal(const std::string& type, const Date& start, const Date& end, double targetValue)
{
	currentGoal = GoalFactory::create(type, start, end, targetValue);
}

void Trainee::logFood(const Food& food, double quantityGrams, const Date& date)
{
	foodDiary.push_back(FoodEntry(food, quantityGrams, date));
	std::cout << "You have successfully logged " << quantityGrams << "g of " << food.getName() << " to your Diary\n";
}

void Trainee::logExercise(const Exercise& e, int duration, const Date& date)
{
	exerciseDiary.push_back(ExerciseEntry(e, duration, date));
	std::cout << "You have successfully logged " << e.getName() << " to your Diary, which trains predominantly " << e.getMuscleGroup() << "\n";
}

void Trainee::viewDailySummary() const
{
	double consumedCalories = 0, protein = 0, carbs = 0, fats = 0, burnedCals = 0;
	for (const auto& food : foodDiary) {
		double multiplier = food.getQuantity() / 100.0;
		consumedCalories += food.getFood().getCalories() * multiplier;
		protein += food.getFood().getProtein() * multiplier;
		carbs += food.getFood().getCarbs() * multiplier;
		fats += food.getFood().getFats() * multiplier;
	}
	for (const auto& exercise : exerciseDiary) {
		burnedCals += exercise.calculateBurnedCalories();
	}
	std::cout << "Your daily activity has burned " << burnedCals << " calories.\n";
	std::cout << "You have consumed " << consumedCalories << " calories with: " << protein << " g of protein| " << carbs << " g of carbs| " << fats << " g of fats.\n";

	double netBalance = consumedCalories - burnedCals - calculateBMR();
	std::cout << "Your net calorie balance is " << netBalance << " kcal\n";
}

void Trainee::viewProgress() const
{
	if (currentGoal) {
		std::cout << currentGoal->getProgress(this->profile);
	}
}

void Trainee::calculateBMI() const
{
	double bmi = profile.getWeight() / (pow(profile.getHeight() / 100.0, 2));
	std::cout << "Your Body Mass Index is: " << bmi << "\n";
}

double Trainee::calculateBMR() const
{
	double bmr = 10 * profile.getWeight() + 6.25 * profile.getHeight() - 5.0 * profile.getAge();
	if (profile.getGender() == Gender::male) { bmr += 5.0; }
	else { bmr -= 161.0; }
	return bmr;
}

std::vector<const Exercise*> Trainee::generateWorkoutPlan(int duration, const std::vector<Exercise>& allExercises) const
{
	std::vector<const Exercise*> pool;
	for (const auto& ex : allExercises) {
		pool.push_back(&ex);
	}
	if (pool.empty())
	{
		std::cout << "Your exercise list is empty, you need to add some exercises first.\n";
		return{};
	}
	std::sort(pool.begin(), pool.end(), [](const Exercise* lhs, const Exercise* rhs) {return lhs->getCaloriesBurned() > rhs->getCaloriesBurned(); });
	std::vector<const Exercise*> workoutPlan;
	int currentDuration = 0;
	for (const auto& exercise : pool) {
		int durationsForExercise = 15;
		if (currentDuration + durationsForExercise > duration)
		{
			durationsForExercise = duration - currentDuration;
		}
		if (durationsForExercise > 0)
		{
			workoutPlan.push_back(exercise);
			currentDuration += durationsForExercise;
		}
		if (currentDuration >= duration)
		{
			break;
		}
	}
	return workoutPlan;
}

void Trainee::addToFavourites(const Exercise* exercise)
{
	if (!exercise)
	{
		return;
	}
	for (const auto& fav : favoriteExercises) {
		if (exercise->getId() == fav->getId())
		{
			std::cout << "This exercise is already in favourites\n";
			return;
		}
	}
	favoriteExercises.push_back(exercise);
	std::cout << "Exercise " << exercise->getName() << " has been added to favourites\n";
}

void Trainee::viewFavourites() const
{
	std::cout << "Favourite exercises: ";
	for (const auto& exercise : favoriteExercises) {
		exercise->printExercise();
	}
}
