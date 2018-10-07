using Caliburn.Micro;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyFitnessPlanner.ViewModels
{
    public class AddProductViewModel : Screen
    {
        private string _name;
        private int _quantity;
        private int _calories;
        private float _protein;
        private float _fat;
        private float _carbohydrates;

        public string Name
        {
            get { return _name; }
            set { _name = value; NotifyOfPropertyChange(() => Name); }
        }

        public int Quantity
        {
            get { return _quantity; }
            set { _quantity = value; NotifyOfPropertyChange(() => Quantity); }
        }
        
        public int Calories
        {
            get { return _calories; }
            set { _calories = value; NotifyOfPropertyChange(() => Calories); }
        }
        
        public float Protein
        {
            get { return _protein; }
            set { _protein = value; NotifyOfPropertyChange(() => Protein); }
        }
        
        public float Fat
        {
            get { return _fat; }
            set { _fat = value; NotifyOfPropertyChange(() => Fat); }
        }
        
        public float Carbohydrates
        {
            get { return _carbohydrates; }
            set { _carbohydrates = value; NotifyOfPropertyChange(() => Carbohydrates); }
        }

        public bool CanAddToDatabase(string name, int quantity, int calories, float protein, float fat, float carbohydrates)
        {
            if (String.IsNullOrWhiteSpace(name) || quantity==0)
                return false;
            else
                return true;
        }
        
        public void AddToDatabase(string name, int quantity, int calories, float protein, float fat, float carbohydrates)
        {
            DataAccessModel db = new DataAccessModel();

            db.InsertProduct(Name, Quantity, Calories, Protein, Fat, Carbohydrates);

            ClearText();
        }

        private void ClearText()
        {
            Name = "";
            Quantity = 0;
            Calories = 0;
            Protein = 0;
            Fat = 0;
            Carbohydrates = 0;
        }
    }
}
