#include <string>
#include <vector>

class GameNumber {
public:
    GameNumber ();
    GameNumber (std::vector<GameNumber>& left, std::vector<GameNumber>& right);
    GameNumber (const std::string& string_representation);
    GameNumber (const GameNumber&);
    GameNumber (GameNumber&&);
    ~GameNumber ();

    GameNumber& operator = (const GameNumber&);
    GameNumber& operator = (const GameNumber&&);

    void get_fraction();
    void get_float();

    bool is_surreal();
private:
    std::vector<GameNumber*> left;
    std::vector<GameNumber*> right;

    GameNumber get_max_L();
    GameNumber get_min_R();
};