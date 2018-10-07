using Caliburn.Micro;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyFitnessPlanner.ViewModels
{
    public class AddMealViewModel : Screen
    {
        private string _name;
        private List<ProductModel> _products;
        private ProductModel _selectedProduct;
        private DateTime _date;
        private int _quantity;
        private ProductModel _product;

        public ProductModel Product
        {
            get { return _product; }
            set { _product = value; }
        }

        public int Quantity
        {
            get { return _quantity; }
            set { _quantity = value; NotifyOfPropertyChange(() => Quantity); }
        }

        public DateTime Date
        {
            get { return _date; }
            set { _date = value; }
        }

        public ProductModel SelectedProduct
        {
            get { return _selectedProduct; }
            set { _selectedProduct = value; NotifyOfPropertyChange(() => SelectedProduct); }
        }

        public List<ProductModel> Products
        {
            get { return _products; }
            set { _products = value; NotifyOfPropertyChange(() => Products); }
        }

        public string Name
        {
            get { return _name; }
            set { _name = value; }
        }

        public AddMealViewModel()
        {
            Products = new List<ProductModel>();

            GetProducts();

            Date = DateTime.Now;
        }

        public void GetProducts()
        {
            DataAccessModel db = new DataAccessModel();

            Products = db.GetProducts();

            SetSelectedProduct();
        }

        public void SearchProduct()
        {
            DataAccessModel db = new DataAccessModel();

            Products = db.GetProductsByName(Name);

            SetSelectedProduct();
        }

        public bool CanAddToDatabase(int quantity, ProductModel selectedProduct)
        {
            if (quantity == 0)
                return false;
            else
                return true;
        }

        public void AddToDatabase(int quantity, ProductModel selectedProduct)
        {
            DataAccessModel db = new DataAccessModel();

            CalculateNutritionalValue();

            db.InsertMeal(Product, Date);

            Clear();
        }

        private void CalculateNutritionalValue()
        {
            Product = new ProductModel();

            float ratio = Quantity / SelectedProduct.Quantity;
            Product.Name = SelectedProduct.Name;
            Product.Quantity = Quantity;
            Product.Calories = SelectedProduct.Calories * ratio;
            Product.Protein = SelectedProduct.Protein * ratio;
            Product.Fat = SelectedProduct.Fat * ratio;
            Product.Carbohydrates = SelectedProduct.Carbohydrates * ratio;
        }

        private void Clear()
        {
            Quantity = 0;
        }

        private void SetSelectedProduct()
        {
            SelectedProduct = Products[0];
        }
    }
}
