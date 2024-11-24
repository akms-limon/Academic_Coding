#include <iostream>
#include <string>
#include <cctype>
#include <set>
#include <vector>

using namespace std;

set<string> KEYWORDS = {"int", "main", "float", "if", "else", "while", "return", "for", "string"};
set<string> OPERATORS = {"+", "-", "*", "/", "=", "==", "!=", "&&", "||"};
set<char> SEPARATORS = {';', ',', '(', ')', '{', '}', ' '};
set<char> LITERALS = {'\"'};

bool is_keyword(const string& word) {
    return KEYWORDS.find(word) != KEYWORDS.end();
}

bool is_operator(const string& op) {
    return OPERATORS.find(op) != OPERATORS.end();
}

bool is_separator(char c) {
    return SEPARATORS.find(c) != SEPARATORS.end();
}

bool is_digit(char c) {
    return isdigit(c);
}

bool is_identifier(char c) {
    return isalnum(c) || c == '_';
}

vector<pair<string, string>> tokenize(const string& code) {
    vector<pair<string, string>> tokens;
    int n = code.length();
    string current_token = "";
    bool in_string = false;

    for (int i = 0; i < n; ++i) {
        char c = code[i];

        if (c == '\"' && !in_string) {
            if (!current_token.empty()) {
                tokens.push_back({"IDENTIFIER", current_token});
                current_token = "";
            }
            in_string = true;
            current_token += c;
        }
        else if (c == '\"' && in_string) {
            current_token += c;
            tokens.push_back({"LITERAL", current_token});
            current_token = "";
            in_string = false;
        }
        else if (in_string) {
            current_token += c;
        }
        else if (is_separator(c)) {
            if (!current_token.empty()) {
                if (is_keyword(current_token)) {
                    tokens.push_back({"KEYWORD", current_token});
                }
                else if (isdigit(current_token[0])) {
                    bool is_float = false;
                    for (char ch : current_token) {
                        if (ch == '.') {
                            is_float = true;
                            break;
                        }
                    }
                    if (is_float) {
                        tokens.push_back({"LITERAL_FLOAT", current_token});
                    } else {
                        tokens.push_back({"LITERAL_INT", current_token});
                    }
                }
                else if (is_identifier(current_token[0])) {
                    tokens.push_back({"IDENTIFIER", current_token});
                }
                else {
                    tokens.push_back({"UNKNOWN", current_token});
                }
                current_token = "";
            }
            if (c != ' ') {
                tokens.push_back({"SEPARATOR", string(1, c)});
            }
        }
        else if (is_operator(string(1, c))) {
            if (!current_token.empty()) {
                tokens.push_back({"IDENTIFIER", current_token});
                current_token = "";
            }
            tokens.push_back({"OPERATOR", string(1, c)});
        }
        else if (is_identifier(c)) {
            current_token += c;
        }
        else {
            if (!current_token.empty()) {
                tokens.push_back({"UNKNOWN", current_token});
                current_token = "";
            }
        }
    }

    if (!current_token.empty()) {
        if (is_keyword(current_token)) {
            tokens.push_back({"KEYWORD", current_token});
        }
        else if (isdigit(current_token[0])) {
            bool is_float = false;
            for (char ch : current_token) {
                if (ch == '.') {
                    is_float = true;
                    break;
                }
            }
            if (is_float) {
                tokens.push_back({"LITERAL_FLOAT", current_token});
            } else {
                tokens.push_back({"LITERAL_INT", current_token});
            }
        }
        else if (is_identifier(current_token[0])) {
            tokens.push_back({"IDENTIFIER", current_token});
        }
        else {
            tokens.push_back({"UNKNOWN", current_token});
        }
    }

    return tokens;
}

int main() {
    string code = R"(
    int main() {
        int x = 10;
        float y = 3.14;
        string s = "hello world";
        if (x > y) {
            return x + y;
        }
    }
    )";

    vector<pair<string, string>> tokens = tokenize(code);

    for (const auto& token : tokens) {
        cout << token.first << ": " << token.second << endl;
    }

    return 0;
}
