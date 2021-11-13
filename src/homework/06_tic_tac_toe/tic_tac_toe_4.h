//h
#include "tic_tac_toe.h"

class Tic_tac_toe_4 : public Tic_tac_toe
{
    public:
        Tic_tac_toe_4(): Tic_tac_toe(4){};
        
    private:
        bool check_diagonal_win();
        bool check_row_win();
        bool check_column_win();

    protected:

};