#pragma once
# include <iostream>
# include <fstream>
# include <vector>
# include <sstream>
# include "piece.h"
# include <memory>

struct ChessPosition {
    std::string name;
    std::string date;
    std::vector<std::shared_ptr<piece>> pieceTab;
    bool whoToMove = 0;
    bool whiteCastle = 0;
    bool blackCastle = 0;
};

class ChessDatabase 
{
public:
    std::vector<ChessPosition> positions;

    void addPosition(const ChessPosition& position);


    void savePositionsToFile();

    std::vector<ChessPosition> loadPositionsFromFile();

    bool printAllPositions();
};