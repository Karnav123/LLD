#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class PizzaFactory
{
public:
    void createPizza()
    {
    }
};

class Pizza
{
public:
    ~Pizza() = default;

    virtual void prepare()
    {
        cout << "Preparing " << m_name << endl;
        cout << "Tossing dough... " << endl;
        cout << "Adding sauce... " << endl;
        cout << "Adding toppings... " << endl;
        for (auto topping : m_toppings)
        {
            cout << "  " << topping << endl;
        }
    }

    virtual void bake()
    {
        cout << "Bake for 25 minutes" << endl;
    }

    virtual void cut()
    {
        cout << "Cut slices" << endl;
    }

    virtual void box()
    {
        cout << "Put pizza in a box" << endl;
    }

    virtual string getName()
    {
        return m_name;
    }

protected:
    string m_name;
    string m_dough;
    string m_sause;
    vector<string> m_toppings;
};

class NYCheesePizza : public Pizza
{
public:
    NYCheesePizza()
    {
        m_name = "NY style cheese pizza.";
        m_dough = "Thin crust.";
        m_sause = "Marinara";

        m_toppings.push_back("Grated Raggiano Cheese");
    }
};

class ChicagoCheesePizza : public Pizza
{
public:
    ChicagoCheesePizza()
    {
        m_name = "Chicago style cheese pizza.";
        m_dough = "Thick crust.";
        m_sause = "Tomato sauce.";

        m_toppings.push_back("Shredded Mozzarella Cheese");
    }

    void cut()
    {
        cout << "Cutting chicago pizza." << endl;
    }
};

class PizzaStore
{
public:
    virtual unique_ptr<Pizza> createPizza(const string &pizzaType) = 0;

    unique_ptr<Pizza> orderPizza(const string &type)
    {
        unique_ptr<Pizza> pizza = createPizza(type);

        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();

        return pizza;
    }
};

class NYPizzaStore : public PizzaStore
{
public:
    unique_ptr<Pizza> createPizza(const string &pizzaType) override
    {
        unique_ptr<Pizza> pizza{nullptr};
        if (pizzaType == "cheese")
        {
            pizza = make_unique<NYCheesePizza>();
        }

        return pizza;
    }
};

class ChicagoPizzaStore : public PizzaStore
{
public:
    unique_ptr<Pizza> createPizza(const string &pizzaType) override
    {
        unique_ptr<Pizza> pizza{nullptr};
        if (pizzaType == "cheese")
        {
            pizza = make_unique<ChicagoCheesePizza>();
        }

        return pizza;
    }
};

int main()
{
    auto nyStore = make_unique<NYPizzaStore>();
    auto chiStore = make_unique<ChicagoPizzaStore>();

    auto pizza = nyStore->orderPizza("cheese");
    cout << "Arnav Ordered " << pizza->getName() << endl;

    pizza = chiStore->orderPizza("cheese");
    cout << "Kumar Ordered " << pizza->getName() << endl;
}