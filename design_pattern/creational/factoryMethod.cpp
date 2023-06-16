// https://www.modernescpp.com/index.php/factory-method
#include <iostream>
#include <memory>

// Product
class Window{ 
 public: 
    virtual std::unique_ptr<Window> create() { 
        std::cout << "Create Window" << '\n';
        return std::make_unique<Window>();
    } 
};

// Concrete Products 
class DefaultWindow: public Window {
    std::unique_ptr<Window> create() override { 
        std::cout << "Create DefaultWindow" << '\n';
        return std::make_unique<DefaultWindow>();
    } 
};

class FancyWindow: public Window {
    std::unique_ptr<Window> create() override { 
        std::cout << "Create FancyWindow" << '\n';
        return std::make_unique<FancyWindow>();
    } 
};

// Concrete Creator or Client
std::unique_ptr<Window> createWindow(std::unique_ptr<Window>&& oldWindow) { 
    return oldWindow->create();
}
  
int main() {

    std::cout << '\n';

    const auto window1 = createWindow(std::make_unique<Window>());
    const auto defaultWindow1 = createWindow(std::make_unique<DefaultWindow>());
    const auto fancyWindow1 = createWindow(std::make_unique<FancyWindow>());

    std::cout << '\n';
  
}