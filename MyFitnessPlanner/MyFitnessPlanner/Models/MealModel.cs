using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyFitnessPlanner.Models
{
    public class MealModel
    {
        public int Id { get; set; }
        public float Quantity { get; set; }
        public DateTime Date { get; set; }
        public int Product_ID { get; set; }

        public string Name { get; set; }
        public float Calories { get; set; }
        public float Protein { get; set; }
        public float Carbohydrates { get; set; }
        public float Fat { get; set; }

        private string _all;

        public string All
        {
            get { return _all; }
            set { _all = value; }
        }

        public void AddValuesFromDb(ProductModel product)
        {
            Name = product.Name;
            Calories = product.Calories * Quantity / product.Quantity;
            Protein = product.Protein * Quantity / product.Quantity;
            Fat = product.Fat * Quantity / product.Quantity;
            Carbohydrates = product.Carbohydrates * Quantity / product.Quantity;
            JoinStrings();
        }

        private void JoinStrings()
        {
            All = Name + " " + Quantity.ToString() + " " + Calories.ToString() + " " + Protein.ToString() + " " + Carbohydrates.ToString() + " " + Fat.ToString();
        }
    }
}
