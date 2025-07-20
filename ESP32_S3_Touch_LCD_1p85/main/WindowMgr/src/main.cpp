
#include <iostream>
#include "WindowManager.h"

int main() {
    auto& wm = WindowManager::getInstance();
    auto  w1 = wm.createWindow("Window 1");
    auto  w2 = wm.createWindow("Window 2");

    wm.switchToWindow(w1->getId());
    auto currentWindow = wm.getCurrentWindow();
    if(currentWindow) {
        std::cout << "Current Window ---> " << currentWindow->getTitle() << std::endl;
    }

    wm.switchToWindow(w2->getId());
    currentWindow = wm.getCurrentWindow();
    if(currentWindow) {
        std::cout << "Current Window ---> " << currentWindow->getTitle() << std::endl;
    }

    wm.closeWindow(w1->getId());

    wm.closeWindow(w2->getId());

    return 0;
}
