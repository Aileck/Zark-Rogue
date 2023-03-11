#include "InputProcessor.h"
#include <cctype>

bool InputProcessor::ProcessInput(string input, World* world)
{
    {
        //Input to lowercase
        string lower_input;
        for (char c : input) {
            lower_input += tolower(c);
        }

        //Split user token to two parts, action + target
        stringstream ss(lower_input);
        string word;
        vector<string> words;

        while (ss >> word) {
            words.push_back(word);
        }

        string action = words[0];
        string target;
        for (int i = 1; i < words.size(); ++i) {
            target += words[i];
            if (i != words.size() - 1) {
                target += " ";
            }
        }
        
        //Default value to deal GOTO action
        int destiny = 0;

        InputType actiontype = InputToAction(action);

        switch (actiontype)
        {
            case InputProcessor::CHECK:
                Check(world->GetCurrentScene(), target);
                break;
            case InputProcessor::GOTO:
                destiny = Goto(world->GetCurrentScene(), target);
                if (destiny > 0) {
                    world->GotoScene(destiny);
                    
                }
                break;
            case InputProcessor::ATTACK:
                break;
            case InputProcessor::TALK:
                break;
            case InputProcessor::INVENTORY:
                break;
            case InputProcessor::USE:
                Use(world, target);
                break;
            case InputProcessor::PICK:
                break;
            case InputProcessor::HELP:
                break;
            case InputProcessor::NOTREGISTERED:
                cout << "This is not a valid command." << endl;
                break;
            default:
                break;
        }

        return true;
    }
}

InputProcessor::InputType InputProcessor::InputToAction(string s)
{
    if (s == "check" || s == "c") {
        return CHECK;
    }
    if (s == "goto" || s == "go") {
        return GOTO;
    }
    if (s == "attack" || s == "a") {
        return ATTACK;
    }
    if (s == "talk" || s == "c") {
        return CHECK;
    }
    if (s == "inventory" || s == "i") {
        return INVENTORY;
    }
    if (s == "use" || s == "u") {
        return USE;
    }
    if (s == "pick" || s == "p") {
        return PICK;
    }
    if (s == "help" || s == "h") {
        return HELP;
    }
    return NOTREGISTERED;
}

void InputProcessor::Check(Scene* s, string target)
{
    Checkeable* c = s->IfContains(target);
    if (c->GetName() == "Nothing") {
        cout << "There's no *" + target + "* here that you're looking for." << endl;
    }
    
}
int InputProcessor::Goto(Scene* s, string target) {
    string hint = "";
    if (target == "n") {
        hint = "(north)";
    }
    if (target == "w") {
        hint = "(west)";
    }
    if (target == "s") {
        hint = "(south)";
    }
    if (target == "e") {
        hint = "(east)";
    }

    if (target.length() == 0) {
        cout << "Where would you like to go?" << endl;
        cout << endl;
        return 0;
    }

    int targetScene = s->CheckDestination(target);
    if (targetScene == -1) {
        cout << "The *" + target + "* direction does not exist.You can try going east, south, west, or north." << endl;
    }
    else if (targetScene == 0) {
        cout << "It appears that there is no road in *" + target + "* " + hint + " you are trying to go.Perhaps you could try a different direction?" << endl;
    }
    else {
        if (target != "hidden")
            cout << "You are trying to move towards *" + target + "* " + hint + "." << endl;

        if (target == "hidden")
            cout << "You start to look for a * hidden * passage. " << endl;
    }
    cout << endl;

    return targetScene;
}

void InputProcessor::Use(World * w, string target)
{
    //Search scene
     
     //Search inventory
}