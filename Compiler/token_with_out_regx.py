import string

KEYWORDS = {"int", "main", "float", "if", "else", "while", "return", "for", "string"}
OPERATORS = {'+', '-', '*', '/', '=', '==', '!=', '&&', '||'}
SEPARATORS = {';', ',', '(', ')', '{', '}', ' '}
LITERALS = {'"'} 

def is_keyword(word):
    return word in KEYWORDS

def is_operator(c):
    return c in OPERATORS

def is_separator(c):
    return c in SEPARATORS

def is_digit(c):
    return c.isdigit()

def is_identifier(c):
    return c.isalnum() or c == '_'

def is_literal_char(c):
    return c.isdigit() or c in string.ascii_letters or c == '"'

def tokenize(code):
    tokens = []
    i = 0
    n = len(code)
    current_token = ''
    in_string = False 
    
    while i < n:
        c = code[i]
        
        if c == '"' and not in_string:
            if current_token:
                tokens.append(('IDENTIFIER', current_token))
                current_token = ''
            in_string = True
            current_token += c
        elif c == '"' and in_string:
            current_token += c
            tokens.append(('LITERAL', current_token))
            current_token = ''
            in_string = False
        
        elif in_string:
            current_token += c
        
        elif is_separator(c):
            if current_token:
                if is_keyword(current_token):
                    tokens.append(('KEYWORD', current_token))
                elif current_token.isdigit():
                    tokens.append(('LITERAL', current_token))
                elif is_identifier(current_token[0]):
                    tokens.append(('IDENTIFIER', current_token))
                else:
                    tokens.append(('UNKNOWN', current_token))
                current_token = ''
            if c != ' ':
                tokens.append(('SEPARATOR', c))
        
        elif is_operator(c):
            if current_token:
                tokens.append(('IDENTIFIER', current_token))
                current_token = ''
            tokens.append(('OPERATOR', c))
        
        elif is_identifier(c):
            current_token += c
        
        else:
            if current_token:
                tokens.append(('UNKNOWN', current_token))
                current_token = ''
        
        i += 1
    
    if current_token:
        if is_keyword(current_token):
            tokens.append(('KEYWORD', current_token))
        elif current_token.isdigit():
            tokens.append(('LITERAL', current_token))
        elif is_identifier(current_token[0]):
            tokens.append(('IDENTIFIER', current_token))
        else:
            tokens.append(('UNKNOWN', current_token))
    
    return tokens

if __name__ == "__main__":
    code = '''
    int main() {
        int x = 10;
        float y = 3.14;
        string s = "hello world";
        if (x > y) {
            return x + y;
        }
    }
    '''
    
    tokens = tokenize(code)
    for token in tokens:
        print(f'{token[0]}: {token[1]}')
