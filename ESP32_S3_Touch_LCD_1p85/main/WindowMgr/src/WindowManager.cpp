#include <iostream>
#include <algorithm>
#include "WindowManager.h"

WindowManager& WindowManager::getInstance() {
    static WindowManager instance;
    std::cout << "WindowManager::getInstance" << std::endl;
    return instance;
}

std::shared_ptr<Window> WindowManager::createWindow(const std::string& title) {
    int id = windows_.size() + 1;
    auto window = std::make_shared<Window>(id, title);
    windows_.push_back(window);
    if(windows_.size() == 1) {
        currentWindowId_ = id;
    }
    std::cout << "WindowManager::createWindow" << std::endl;
    return window;
}

void WindowManager::switchToWindow(int id) {
    auto window = findWindowById( id );
    if(window) {
        currentWindowId_ = id;
    }
    std::cout << "WindowManager::switchToWindow" << std::endl;
}

void WindowManager::closeWindow(int id) {
    auto it = std::remove_if(
                windows_.begin(), windows_.end(), 
                [id](std::shared_ptr<Window> w) {return id == w->getId();}
            );
    if(it != windows_.end()) {
        windows_.erase(it, windows_.end());
        if(currentWindowId_ == id && !windows_.empty()) {
            currentWindowId_ = windows_.front()->getId();
        } else if(windows_.empty()) {
            currentWindowId_ = -1;
        }
    }
    std::cout << "WindowManager::closeWindow" << std::endl;
}

std::shared_ptr<Window> WindowManager::getCurrentWindow() {
    std::cout << "WindowManager::getCurrentWindow" << std::endl;
    return findWindowById(currentWindowId_);
}

std::shared_ptr<Window> WindowManager::findWindowById(int id) {
    std::cout << "WindowManager::findWindowById" << std::endl;
    for(auto& window : windows_) {
        if(id == window->getId()) {
            return window;
        }
    }
    return nullptr; 
}


