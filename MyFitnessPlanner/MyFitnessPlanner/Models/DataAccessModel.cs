using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Dapper;
using System.Data;
using System.Data.SqlClient;
using System.Configuration;
using MyFitnessPlanner.Models;

namespace MyFitnessPlanner
{
    public class DataAccessModel
    {
        public List<ProductModel> GetProducts()
        {
            using (IDbConnection connection = new SqlConnection(Helper.CnnVal("MyFitnessPlanner.Properties.Settings.Setting")))
            {
                if (connection.State == ConnectionState.Closed)
                    connection.Open();

                return connection.Query<ProductModel>("select * from Product").ToList();
            }
        }

        public List<ProductModel> GetProductsByName(string name)
        {
            using (IDbConnection connection = new SqlConnection(Helper.CnnVal("MyFitnessPlanner.Properties.Settings.Setting")))
            {
                if (connection.State == ConnectionState.Closed)
                    connection.Open();

                return connection.Query<ProductModel>($"select * from Product where Name like '%{ name }%'").ToList();
            }
        }

        public void InsertProduct(string name, int quantity, int calories, float protein, float fat, float carbohydrates)
        {
            using (IDbConnection connection = new SqlConnection(Helper.CnnVal("MyFitnessPlanner.Properties.Settings.Setting")))
            {
                if (connection.State == ConnectionState.Closed)
                    connection.Open();

                List<ProductModel> products = new List<ProductModel>();
                products.Add(new ProductModel { Name = name, Quantity = quantity, Calories = calories, Carbohydrates = carbohydrates, Protein = protein, Fat = fat });

                connection.Execute("insert into Product(Name, Quantity, Calories, Carbohydrates, Protein, Fat) values(@name, @quantity, @calories, @carbohydrates, @protein, @fat)", products);
            }
        }

        public void InsertMeal(ProductModel product, DateTime date)
        {
            using (IDbConnection connection = new SqlConnection(Helper.CnnVal("MyFitnessPlanner.Properties.Settings.Setting")))
            {
                if (connection.State == ConnectionState.Closed)
                    connection.Open();

                int id = connection.QuerySingle<int>($"select id from Product where Name like '{product.Name}'");

                List<MealModel> meal = new List<MealModel>();
                meal.Add(new MealModel { Id = id, Date = date, Quantity = product.Quantity });

                List<DayModel> day = new List<DayModel>();
                day.Add(new DayModel() { Date = date.Date, Calories = product.Calories, Fat = product.Fat, Carbohydrates = product.Carbohydrates, Protein = product.Protein });

                CreateDayIfNotCreated(date);

                connection.Execute("insert into Meal(Date, Product_ID, Quantity) values (@date, @id, @quantity)", meal);

                connection.Execute($"update Day set Calories = Calories + @Calories, Protein = Protein + @Protein, Fat = Fat + @Fat, Carbohydrates = Carbohydrates + @Carbohydrates where Date = @Date", day);
            }
        }

        public DayModel GetDay(DateTime date)
        {
            using (IDbConnection connection = new SqlConnection(Helper.CnnVal("MyFitnessPlanner.Properties.Settings.Setting")))
            {
                if (connection.State == ConnectionState.Closed)
                    connection.Open();

                return connection.QuerySingleOrDefault<DayModel>("select * from Day where Date = @date", date);
            }
        }

        public List<MealModel> GetMeals(DateTime date)
        {
            using (IDbConnection connection = new SqlConnection(Helper.CnnVal("MyFitnessPlanner.Properties.Settings.Setting")))
            {
                if (connection.State == ConnectionState.Closed)
                    connection.Open();
                
               return connection.Query<MealModel>("select * from Meal where Date = @date", date).ToList();
            }
        }

        public ProductModel GetMealValues(int id)
        {
            using (IDbConnection connection = new SqlConnection(Helper.CnnVal("MyFitnessPlanner.Properties.Settings.Setting")))
            {
                if (connection.State == ConnectionState.Closed)
                    connection.Open();

                return connection.QuerySingleOrDefault<ProductModel>("select * from Product where ID = @i", new { i = id});
            }
        }

        private void CreateDayIfNotCreated(DateTime date)
        {
            using (IDbConnection connection = new SqlConnection(Helper.CnnVal("MyFitnessPlanner.Properties.Settings.Setting")))
            {
                if (connection.State == ConnectionState.Closed)
                    connection.Open();

                List<DateTime> datelist = new List<DateTime>();

                datelist = connection.Query<DateTime>("select Date from Day").ToList();

                foreach (DateTime d in datelist)
                {
                    if (d.Date == date.Date)
                        return;
                }

                    connection.Execute("insert into Day(Date, Calories, Protein, Fat, Carbohydrates) values (@date, 0, 0, 0, 0)", date);
            }
        }
    }
}
