using Caliburn.Micro;
using MyFitnessPlanner.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;

namespace MyFitnessPlanner.ViewModels
{
    class MyMealsViewModel : Screen
    {
        private DateTime _date;
        private DayModel _selectedDay;
        private List<MealModel> _meals;
        private MealModel _selectedMeal;
        private ProductModel _product;

        public ProductModel Product
        {
            get { return _product; }
            set { _product = value; }
        }

        public MealModel SelectedMeal
        {
            get { return _selectedMeal; }
            set { _selectedMeal = value; NotifyOfPropertyChange(() => SelectedMeal); }
        }
        
        public List<MealModel> Meals
        {
            get { return _meals; }
            set { _meals = value; NotifyOfPropertyChange(() => Meals); }
        }

        public DayModel SelectedDay
        {
            get { return _selectedDay; }
            set { _selectedDay = value; NotifyOfPropertyChange(() => SelectedDay); }
        }

        public DateTime Date
        {
            get { return _date; }
            set { _date = value; DateHasChanged(); }
        }

        public MyMealsViewModel()
        {
            Date = DateTime.Now;

            GetDay();

            GetMeals();
        }

        private void GetDay()
        {
            DataAccessModel db = new DataAccessModel();

            SelectedDay = db.GetDay(Date);
        }

        private void DateHasChanged()
        {
            GetDay();

            GetMeals();
        }

        private void GetMeals()
        {
            DataAccessModel db = new DataAccessModel();

            Meals = db.GetMeals(Date);
            
            foreach (MealModel m in Meals)
            {
                Product = db.GetMealValues(m.Product_ID);
                m.AddValuesFromDb(Product);
            }
        }
    }
}
