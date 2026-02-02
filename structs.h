#define MAX_TYPES 18
#define MAX_MOVES 486
#define MAX_POKEMONS 1015
#define MAX_NAME_LEN 30



typedef enum {
    PHYSICAL,
    SPECIAL
} Category;

typedef struct {
    char atkName[MAX_NAME_LEN];
    char defName[MAX_NAME_LEN];
    float multiplier;
} TypeEffect;

typedef struct {
    char name[MAX_NAME_LEN];
    TypeEffect effects[MAX_TYPES];
} Type;

typedef struct {
    char name[MAX_NAME_LEN];
    Type type;
    Category category;
    float power;
} Move;

typedef struct {
    char name[MAX_NAME_LEN];
    int maxHP;
    int currentHP;
    int attack;
    int defense;
    int spAtk;
    int spDef;
    int speed;
    Type types[2];
    Move moves[4];
} Pokemon;

typedef struct {
    char name[MAX_NAME_LEN];
    Pokemon team[6];
    int currentIndex;
} Player;

void game(Player *player1, Player *player2, Type type[]);
void roundD(Player *player1, Player *player2, Type type[],int roundnumber );
int attack(Player *player1, Player *player2, int moveIndex, Type type[]);
float findefective(Player *player1, Player *player2,  int moveIndex , Type type[]);
int change(Player *player, int changeChoose);
void initialize(Type types[], Move moves[], Pokemon pokemons[],Player *player1, Player *player2);
