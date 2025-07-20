
#include <iostream>
#include "Window.h"
#include "WindowManager.h"

Window::Window(int id, const std::string& title)
    :id_(id), title_(title), visiable_(true)
{
    std::cout << "Window::Window Constructor..." << std::endl;
}

Window::~Window() {
    std::cout << "Window::Window Destructor..." << std::endl;
}

int Window::getId() const {
    return id_;
}

std::string Window::getTitle() const {
    return title_;
}

bool Window::isVisiable() const {
    return visiable_;
}

void Window::show() {
    visiable_ = true;
    std::cout << "Window::show()" << std::endl; 
}

void Window::hide() {
    visiable_ = false;
    std::cout << "Window::hide" << std::endl;
}

void Window::updateTitle(const std::string& title) {
    this->title_ = title;
    std::cout << "Window::updateTitle" << std::endl;
}

