
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iomanip>
#include <map>

struct Goal { // Izvor: https://www.kaggle.com/datasets/azminetoushikwasi/lionel-messi-vs-cristiano-ronaldo-club-goals
    std::string player;
    std::string season;
    std::string competition;
    int matchday;
    std::string date;
    std::string venue;
    std::string club;
    std::string opponent;
    std::string result;
    std::string playing_position;
    std::string minute;
    std::string at_score;
    std::string type;
    std::string goal_assist;
};

void pomoc() {
    std::cout << std::endl << std::setw(8) << std::left << "Naziv"
        << std::setw(50) << std::left << "Funkcija" << std::endl;
    std::cout << std::setfill('-') << std::setw(70)
        << ""
        << std::setfill(' ')
        << std::endl;

    std::cout << std::setw(8) << std::left << "prvi"
        << std::setw(50) << std::left << "Ispisuje prvi gol Ronalda i Messija" << std::endl
        << std::setw(8) << std::left << "zadnji"
        << std::setw(50) << std::left << "Ispisuje zadnji gol Ronalda i Messija" << std::endl
        << std::setw(8) << std::left << "klupski"
        << std::setw(50) << std::left << "Ispisuje broj golova u svakom klubu Ronalda i Messija" << std::endl
        << std::setw(8) << std::left << "suma"
        << std::setw(50) << std::left << "Ispisuje broj golova Messija i Ronalda te njihovu sumu" << std::endl
        << std::setw(8) << std::left << "prikazi"
        << std::setw(50) << std::left << "Prikazuje sve golove u vektoru po 5 elemenata" << std::endl
        << std::setw(8) << std::left << "izlaz"
        << std::setw(50) << std::left << "Izade iz programa" << std::endl;

    std::cout << std::endl;
}

void tablica_stupci() { // Ispis naziva stupaca
    std::cout << std::endl << std::setw(20) << std::left << "Player"
        << std::setw(8) << std::left << "Season"
        << std::setw(23) << std::left << "Competition"
        << std::setw(10) << std::left << "Matchday"
        << std::setw(20) << std::left << "Date"
        << std::setw(7) << std::left << "Venue"
        << std::setw(20) << std::left << "Club"
        << std::setw(20) << std::left << "Opponent"
        << std::setw(8) << std::left << "Result"
        << std::setw(18) << std::left << "Playing position"
        << std::setw(8) << std::left << "Minute"
        << std::setw(10) << std::left << "At score"
        << std::setw(20) << std::left << "Type"
        << std::setw(19) << std::left << "Goal assist" << std::endl;

    std::cout << std::setfill('-') << std::setw(205)
        << ""
        << std::setfill(' ')
        << std::endl;
}


int main()
{
    std::vector<Goal> goals;
    std::ifstream in_file{ "data.csv" }; // Izvor: https://www.kaggle.com/datasets/azminetoushikwasi/lionel-messi-vs-cristiano-ronaldo-club-goals
    if (!in_file) {
        std::cerr << "Pogreska u citanju datoteke" << std::endl;
        return 1;
    }

    std::string redak;

    std::getline(in_file, redak);
    while (std::getline(in_file, redak)) {
        std::stringstream ss{ redak };
        Goal gol;
        std::string temp;
        std::getline(ss, gol.player, ',');
        std::getline(ss, gol.season, ',');
        std::getline(ss, gol.competition, ',');
        std::getline(ss, temp, ',');
        std::stringstream broj{ temp };
        broj >> gol.matchday;
        std::getline(ss, gol.date, ',');
        std::getline(ss, gol.venue, ',');
        std::getline(ss, gol.club, ',');
        std::getline(ss, gol.opponent, ',');
        std::getline(ss, gol.result, ',');
        std::getline(ss, gol.playing_position, ',');
        std::getline(ss, gol.minute, ',');
        std::getline(ss, gol.at_score, ',');
        std::getline(ss, gol.type, ',');
        std::getline(ss, gol.goal_assist, ',');
        goals.push_back(gol);
    }

    std::string input{};
    while (input != "izlaz") {
        std::cout << "Sto zelite raditi? ";
        std::cin >> input;
        if (input == "suma") { // Ispisuje broj svih golova Messija i Ronalda te njihov zbroj
            std::cout << std::endl;
            int messi_sum{ 0 }, ronaldo_sum{ 0 };
            for (auto i : goals) {
                if (i.player == "Lionel Messi") {
                    messi_sum++;
                }
                if (i.player == "Cristiano Ronaldo") {
                    ronaldo_sum++;
                }

            }
            std::cout << "Messi - broj golova: " << messi_sum << std::endl
                << "Ronaldo - broj golova: " << ronaldo_sum << std::endl
                << "Ukupan broj golova: " << messi_sum + ronaldo_sum << std::endl << std::endl;
        }
        if (input == "prvi") { // Ispisuje prvi gol Messija i Ronalda
            tablica_stupci();
            std::vector<Goal>::iterator it_ron = std::find_if(goals.begin(), goals.end(), [](const Goal& gol_ron) {return gol_ron.player == "Cristiano Ronaldo"; });
            std::cout << std::setw(20) << std::left << it_ron->player
                << std::setw(8) << std::left << it_ron->season
                << std::setw(23) << std::left << it_ron->competition
                << std::setw(10) << std::left << it_ron->matchday
                << std::setw(20) << std::left << it_ron->date
                << std::setw(7) << std::left << it_ron->venue
                << std::setw(20) << std::left << it_ron->club
                << std::setw(20) << std::left << it_ron->opponent
                << std::setw(8) << std::left << it_ron->result
                << std::setw(18) << std::left << it_ron->playing_position
                << std::setw(8) << std::left << it_ron->minute
                << std::setw(10) << std::left << it_ron->at_score
                << std::setw(20) << std::left << it_ron->type
                << std::setw(19) << std::left << it_ron->goal_assist << std::endl;
            std::vector<Goal>::iterator it_messi = std::find_if(goals.begin(), goals.end(), [](const Goal& gol_messi) {return gol_messi.player == "Lionel Messi"; });
            std::cout << std::setw(20) << std::left << it_messi->player
                << std::setw(8) << std::left << it_messi->season
                << std::setw(23) << std::left << it_messi->competition
                << std::setw(10) << std::left << it_messi->matchday
                << std::setw(20) << std::left << it_messi->date
                << std::setw(7) << std::left << it_messi->venue
                << std::setw(20) << std::left << it_messi->club
                << std::setw(20) << std::left << it_messi->opponent
                << std::setw(8) << std::left << it_messi->result
                << std::setw(18) << std::left << it_messi->playing_position
                << std::setw(8) << std::left << it_messi->minute
                << std::setw(10) << std::left << it_messi->at_score
                << std::setw(20) << std::left << it_messi->type
                << std::setw(19) << std::left << it_messi->goal_assist << std::endl;
            std::cout << std::endl;
        }
        if (input == "zadnji") { // Ispisuje zadnji gol Messija i Ronalda
            tablica_stupci();
            std::vector<Goal>::reverse_iterator it_ron = std::find_if(goals.rbegin(), goals.rend(), [](const Goal& gol_ron) {return gol_ron.player == "Cristiano Ronaldo"; });
            std::cout << std::setw(20) << std::left << it_ron->player
                << std::setw(8) << std::left << it_ron->season
                << std::setw(23) << std::left << it_ron->competition
                << std::setw(10) << std::left << it_ron->matchday
                << std::setw(20) << std::left << it_ron->date
                << std::setw(7) << std::left << it_ron->venue
                << std::setw(20) << std::left << it_ron->club
                << std::setw(20) << std::left << it_ron->opponent
                << std::setw(8) << std::left << it_ron->result
                << std::setw(18) << std::left << it_ron->playing_position
                << std::setw(8) << std::left << it_ron->minute
                << std::setw(10) << std::left << it_ron->at_score
                << std::setw(20) << std::left << it_ron->type
                << std::setw(19) << std::left << it_ron->goal_assist << std::endl;
            std::vector<Goal>::reverse_iterator it_messi = std::find_if(goals.rbegin(), goals.rend(), [](const Goal& gol_messi) {return gol_messi.player == "Lionel Messi"; });
            std::cout << std::setw(20) << std::left << it_messi->player
                << std::setw(8) << std::left << it_messi->season
                << std::setw(23) << std::left << it_messi->competition
                << std::setw(10) << std::left << it_messi->matchday
                << std::setw(20) << std::left << it_messi->date
                << std::setw(7) << std::left << it_messi->venue
                << std::setw(20) << std::left << it_messi->club
                << std::setw(20) << std::left << it_messi->opponent
                << std::setw(8) << std::left << it_messi->result
                << std::setw(18) << std::left << it_messi->playing_position
                << std::setw(8) << std::left << it_messi->minute
                << std::setw(10) << std::left << it_messi->at_score
                << std::setw(20) << std::left << it_messi->type
                << std::setw(19) << std::left << it_messi->goal_assist << std::endl;
            std::cout << std::endl;
        }
        if (input == "prikazi") { // Prikazuje tablicu po 5 elemenata
            tablica_stupci();
            for (size_t i = 0; i < goals.size(); i++) {
                std::cout << std::setw(20) << std::left << goals[i].player
                    << std::setw(8) << std::left << goals[i].season
                    << std::setw(23) << std::left << goals[i].competition
                    << std::setw(10) << std::left << goals[i].matchday
                    << std::setw(20) << std::left << goals[i].date
                    << std::setw(7) << std::left << goals[i].venue
                    << std::setw(20) << std::left << goals[i].club
                    << std::setw(20) << std::left << goals[i].opponent
                    << std::setw(8) << std::left << goals[i].result
                    << std::setw(18) << std::left << goals[i].playing_position
                    << std::setw(8) << std::left << goals[i].minute
                    << std::setw(10) << std::left << goals[i].at_score
                    << std::setw(20) << std::left << goals[i].type
                    << std::setw(19) << std::left << goals[i].goal_assist << std::endl;
                if (i == 5) {
                    std::cout << std::endl << "Dalje ili izlaz? ";
                    std::string odluka;
                    std::cin >> odluka;
                    if (odluka == "dalje") {
                        std::cout << std::endl;
                        tablica_stupci();
                        continue;
                    }
                    if (odluka == "izlaz") {
                        std::cout << std::endl;
                        break;
                    }
                }
                if (i == goals.size()) {
                    std::cout << std::endl << "Proslo ili izlaz? ";
                    std::string odluka;
                    std::cin >> odluka;
                    if (odluka == "izlaz") {
                        std::cout << std::endl;
                        break;
                    }
                    if (odluka == "proslo") {
                        i -= 10;
                        std::cout << std::endl;
                        tablica_stupci();
                    }
                }
                if (i % 5 == 0 && i != 5 && i != 0) {
                    std::cout << std::endl << "Dalje, proslo ili izlaz? ";
                    std::string odluka;
                    std::cin >> odluka;
                    if (odluka == "dalje") {
                        std::cout << std::endl;
                        tablica_stupci();
                        continue;
                    }
                    if (odluka == "izlaz") {
                        std::cout << std::endl;
                        break;
                    }
                    if (odluka == "proslo") {
                        std::cout << std::endl;
                        tablica_stupci();
                        i -= 10;
                    }
                }
            }
        }
        if (input == "klupski") { // Ispisuje broj golova o svim klubovima Messija i Ronalda
            std::cout << std::endl;
            std::map<std::string, int> map_messi{};
            std::map<std::string, int> map_ronaldo{};
            for (auto i : goals) {
                if (i.player == "Lionel Messi") {
                    map_messi[i.club] += 1;
                }
                if (i.player == "Cristiano Ronaldo") {
                    map_ronaldo[i.club] += 1;
                }
            }
            std::cout << "Messi klupski golovi: " << std::endl;
            for (const auto& i : map_messi) {
                std::cout << i.first << ": " << i.second << std::endl;
            }
            std::cout << std::endl;
            std::cout << "Ronaldo klupski golovi: " << std::endl;
            for (const auto& i : map_ronaldo) {
                std::cout << i.first << ": " << i.second << std::endl;
            }
            std::cout << std::endl;
        }
        if (input == "pomoc") { // Izlazi iz while loop-a, odnosno programa
            pomoc();
        }
        if (input == "izlaz") { // Izlazi iz while loop-a, odnosno programa
            std::cout << "Dovidjenja!" << std::endl;
        }
    }

    in_file.close();
    return 0;
}
