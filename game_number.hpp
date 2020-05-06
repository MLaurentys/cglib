#include <string>
#include <vector>

enum class GNRepresentation {
    sets = 0,
    integer = 1,
    real = 2
};

class GameNumber {
public:
    GameNumber ();
    GameNumber (int n);
    GameNumber (float n);
    GameNumber (std::vector<GameNumber*>& left, std::vector<GameNumber*>& right);
    GameNumber (const std::string& string_representation);
    GameNumber (const GameNumber&);
    GameNumber (GameNumber&&);
    ~GameNumber ();

    GameNumber& operator = (const GameNumber&);
    GameNumber& operator = (const GameNumber&&);

    void get_fraction();
    float get_float();

    bool is_surreal();
private:
    std::vector<GameNumber*> left;
    std::vector<GameNumber*> right;
    int inum;
    float fnum;
    GNRepresentation representation;

    GameNumber& get_max_L();
    GameNumber& get_min_R();
};