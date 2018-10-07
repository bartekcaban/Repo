using Caliburn.Micro;
using MyFitnessPlanner.ViewModels;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyFitnessPlanner.Views
{
    public class ShellViewModel : Conductor<object>
    {
        public ShellViewModel()
        {
            ActivateItem(new MyMealsViewModel());
        }

        public void LoadAddMeal()
        {
            ActivateItem(new AddMealViewModel());
        }

        public void LoadAddProduct()
        {
            ActivateItem(new AddProductViewModel());
        }

        public void LoadMyMeals()
        {
            ActivateItem(new MyMealsViewModel());
        }
    }
}
