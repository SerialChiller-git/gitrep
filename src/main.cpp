#include<iostream>
#include<cpr/cpr.h>
#include<nlohmann/json.hpp>
#include<string>
#include<fstream>
#include<vector>
#include <stdio.h>                  // for getchar
#include <ftxui/dom/elements.hpp>   // for filler, text, hbox, vbox
#include <ftxui/screen/screen.hpp>  // for Full, Screen
#include <memory>                   // for allocator
 
#include<ftxui/component/screen_interactive.hpp>
#include<ftxui/component/component_options.hpp>
#include<ftxui/component/component.hpp>
#include<ftxui/component/captured_mouse.hpp>


void openUrl(std::string url){

#ifdef _WIN32
    system(("start " + url).c_str());  // Windows
#elif __APPLE__
    system(("open " + url).c_str());   // macOS
#else
    system(("xdg-open " + url).c_str()); // Linux
#endif
    return;
}

// Function to read the username from config.ini
std::string getGitHubUsername() {
    std::ifstream file("config.ini");
    if (!file) {
        std::cerr << "Error: Could not open config.ini" << std::endl;
        return "";
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.find("username") != std::string::npos) {
            size_t pos = line.find("=");
            if (pos != std::string::npos) {
                return line.substr(pos + 1);  // Extract value after '='
            }
        }
    }

    std::cerr << "Error: Username not found in config.ini" << std::endl;
    return "";
}

int main(int argc, char* argv[]){
    std::string username = getGitHubUsername();
    if (username.empty()) {
        return 1;
    }

    username.erase(0, username.find_first_not_of(" \t"));
    username.erase(username.find_last_not_of(" \t") + 1);
    std::string url = "https://api.github.com/users/" + username + "/repos";
    cpr::Response r;
    
    std::string arg1;
    arg1 = (argc == 2) ? argv[1] : "invalid";
    if(argc < 2){
        r = cpr::Get(cpr::Url{url});
    }
    else if (arg1 == "private"){
        std::string apiKey;
        std::cout << "Input your GitHub personal access token: ";
        std::cin >> apiKey;
        r = cpr::Get(
            cpr::Url{url},
            cpr::Header{{"Authorization", "token " + apiKey}}
        );
    }
    else{
        std::cerr << "invalid argument, try using gitrep private or gitrep ";
        return 1;
    }
    nlohmann::json j;
    //std::cout << "Your url: " << url << "\n";
    auto header = ftxui::vbox({
    ftxui::text(" GitHub Repo Viewer ") | ftxui::bold | ftxui::color(ftxui::Color::Green) | ftxui::center,
    ftxui::separator(),
    ftxui::text("Use Arrow Keys to navigate, Enter to open repo, 'q' to quit.") | ftxui::color(ftxui::Color::Cyan),
    ftxui::separator()
});



try {
    j = nlohmann::json::parse(r.text);
} catch (const std::exception& e) {
    std::cerr << "JSON Parsing Error: " << e.what() << std::endl;
    return 1;
}   
    //std::cout << r.url << "\n";
    //std::cout << j;
    if (r.status_code != 200) {
        std::ifstream backup("pretty.json");
        backup >> j;
        backup.close();
    }
    else{
        std::ofstream backup("pretty.json");
        backup << j.dump(4);
        backup.close();
    }
    std::vector<std::string> repoNames;
    std::vector<std::string> repoUrls;
    for(const auto& repos : j){
        repoUrls.push_back(repos["html_url"].get<std::string>());
        repoNames.push_back(repos["name"].get<std::string>());
    }
    
    auto screen = ftxui::ScreenInteractive::TerminalOutput();
    //std::cout << header;
    ftxui::MenuOption option;
    int selected = 0;
    
        option.on_enter = [&repoUrls, &repoNames, &selected, &screen] { openUrl(repoUrls[selected]);};
        auto menu = ftxui::Menu(&repoNames, &selected, option);
        auto container = ftxui::Container::Vertical({menu});

    
    screen.Loop(ftxui::CatchEvent(container, [&](const ftxui::Event& event) {      
    
        if (event == ftxui::Event::Character('q')) {
            screen.ExitLoopClosure()();
            std::cout << "Exiting...\n";
            return true;  // Event handled
        }
        return false;  // Pass other events
    }));
    std::exit(0);

    return 0;  
}