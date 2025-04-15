# include "ChessDatabase.hpp"
#include "common/systemCls.hpp"


bool ChessDatabase::printAllPositions() 
{
    if (positions.empty())
    {
        clearScreen();
        std::cout << "No positions found." << std::endl;
        return 1;
    }

    for (int i = 0; i < static_cast<int>(positions.size()); i++) {
        std::cout << "Index: " << i  << std::endl;
        std::cout << "Name: " << positions[i].name << std::endl;
        std::cout << "Date: " << positions[i].date << std::endl;
    }
    return 0;
}

void ChessDatabase::addPosition(const ChessPosition& position)
{
    positions.push_back(position);
}

void ChessDatabase::savePositionsToFile()
{
    std::ofstream file("ChessPositions.txt");

    if (file.is_open()) {
        for (const ChessPosition& position : positions) {
            file << "Name: " << position.name << "\n";
            file << "Date: " << position.date << "\n";
            file << "White to castle: " << position.whiteCastle << "\n";
            file << "Black to castle: " << position.blackCastle << "\n";
            file << "Who to move: " << position.whoToMove << "\n";

            for (int i = 0; i < static_cast<int>(position.pieceTab.size()); i++)
            {

                file << position.pieceTab[i]->x << position.pieceTab[i]->y << position.pieceTab[i]->colour << position.pieceTab[i]->typeCharF() << std::endl;
            }

            file << std::endl;
        }

        file.close();
        std::cout << "Positions has been saved in " << "ChessPositions.txt" << std::endl;
    }
    else {
        std::cout << "Error: cannot open file " << std::endl;
    }
}

std::vector<ChessPosition> ChessDatabase::loadPositionsFromFile()
{

    std::ifstream file("ChessPositions.txt");
    ChessPosition position;
    bool isValidPosition = false;
    if (file.is_open()) {

        std::string line;
        while (std::getline(file, line)) {
            if (line.substr(0, 5) == "Name:") {
                if (isValidPosition) {
                    positions.push_back(position);
                    isValidPosition = false;
                }

                position.name = line.substr(6);

                std::getline(file, line);
                position.date = line.substr(6);
                std::getline(file, line);
                position.whiteCastle = (line.substr(16) == "1");
                std::getline(file, line);
                position.blackCastle = (line.substr(16) == "1");
                std::getline(file, line);
                position.whoToMove = (line.substr(13) == "1");

                //position.pieceTab.clear();
                while (std::getline(file, line) && !line.empty()) {
                    int x = std::stoi(line.substr(0, 1));
                    int y = std::stoi(line.substr(1, 1));
                    bool colour = (line.substr(2, 1) == "1");
                    char typeCharF = line.substr(3, 1)[0];

                    std::shared_ptr<Piece> Piece;
                    if (typeCharF == 'Q') {
                        Piece = std::make_shared<Queen>(x, y, colour);
                    }
                    else if (typeCharF == 'R') {
                        Piece = std::make_shared<Rook>(x, y, colour);
                    }
                    else if (typeCharF == 'B') {
                        Piece = std::make_shared<Bishop>(x, y, colour);
                    }
                    else if (typeCharF == 'P') {
                        Piece = std::make_shared<Pawn>(x, y, colour);
                    }
                    else if (typeCharF == 'K') {
                        Piece = std::make_shared<King>(x, y, colour);
                    }
                    else if (typeCharF == 'N') {
                        Piece = std::make_shared<Knight>(x, y, colour);
                    }

                    position.pieceTab.push_back(Piece);
                }

                isValidPosition = true;
            }
        }
    }
    if (isValidPosition) {
        positions.push_back(position);
    }
    file.close();

    return positions;
}