# include "chessDatabase.h"


bool ChessDatabase::printAllPositions() 
{
    if (positions.empty()) {
        std::cout << "No positions found." << std::endl;
        return 1;
    }

    for (int i = 0; i < positions.size(); i++) {
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
    std::ofstream file("ChessPositions.txt",std::ios::app);

    if (file.is_open()) {
        for (const ChessPosition& position : positions) {
            file << "Name: " << position.name << "\n";
            file << "Date: " << position.date << "\n";
            file << "White to castle: " << position.whiteCastle << "\n";
            file << "Black to castle: " << position.blackCastle << "\n";
            file << "Who to move: " << position.whoToMove << "\n";

            for (int i = 0; i < position.pieceTab.size(); i++)
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

    if (file.is_open()) {
        std::vector<ChessPosition> positions;

        std::string line;
        while (std::getline(file, line)) {
            if (line.substr(0, 5) == "Name:")
            {
                ChessPosition position;
                position.name = line.substr(6);

                std::getline(file, line);
                position.date = line.substr(6);
                std::getline(file, line);
                position.whiteCastle = (line.substr(16) == "true");;
                std::getline(file, line);
                position.whiteCastle = (line.substr(16) == "true");
                std::getline(file, line);
                position.whiteCastle = (line.substr(13) == "true");

                while (std::getline(file, line) && !line.empty())
                {
                    int x = std::stoi(line.substr(0, 1));
                    int y = std::stoi(line.substr(1, 1));
                    bool colour = (line.substr(2, 1) == "W");
                    char typeCharF = line.substr(3, 1)[0];

                    std::shared_ptr<piece> piece;
                    if (typeCharF == 'Q')
                    {
                        piece = std::make_shared<queen>(x, y, colour);
                    }
                    else if (typeCharF == 'R')
                    {
                        piece = std::make_shared<rook>(x, y, colour);
                    }
                    else if (typeCharF == 'B')
                    {
                        piece = std::make_shared<bishop>(x, y, colour);
                    }
                    else if (typeCharF == 'P')
                    {
                        piece = std::make_shared<pawn>(x, y, colour);
                    }
                    else if (typeCharF == 'K')
                    {
                        piece = std::make_shared<king>(x, y, colour);
                    }
                    else if (typeCharF == 'N')
                    {
                        piece = std::make_shared<knight>(x, y, colour);
                    }

                    position.pieceTab.push_back(piece);
                }

                positions.push_back(position);
            }
        }

        file.close();


        return positions;
    }
}