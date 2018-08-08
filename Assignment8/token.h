const char number = '#';
const char quit = 'q';
const char print = ';';
const char power = '^';
const char mod = '%';
const char invalid = 'i';
const char name = 'n';
const char root = '|';
const char arrow = '!';

class Token{
public:
    char kind;
    double value;
    string name;
    string c;
    Token(char ch) :kind{ch} {}
    Token(char ch, double val) :kind{ch}, value{val} {}
    Token(char ch, string n) :kind{ch}, name{n} {}
    Token(char ch, char c) :kind{ch}, c{c} {}
};

class Token_stream {
    public:
        Token get();
        void putback(Token t);
        Token popback();
        void ignore(char c);
        vector<string> prev_calcs;
        int prev = 0;
        void create_input(string s);
    private:
        vector<Token> buffer;
};
