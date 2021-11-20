//h
#include "tic_tac_toe.h"

class Tic_tac_toe_3 : public Tic_tac_toe
{
    public:
        Tic_tac_toe_3(): Tic_tac_toe(3){};
        Tic_tac_toe_3(std::vector<std::string> p, std::string winner): Tic_tac_toe(p, winner){};

    private:
        bool check_diagonal_win();
        bool check_row_win();
        bool check_column_win();

    protected:

};