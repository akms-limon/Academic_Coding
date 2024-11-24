import string

# Define categories for different tokens
KEYWORDS = {"int", "float", "if", "else", "while", "return", "for"}
OPERATORS = {'+', '-', '*', '/', '=', '==', '!=', '&&', '||'}
SEPARATORS = {';', ',', '(', ')', '{', '}', ' '}
LITERALS = {'"'}  # Used for string literals, the program will handle quotes inside.

def is_keyword(word):
    """Check if a word is a keyword."""
    return word in KEYWORDS

def is_operator(c):
    """Check if a character is an operator."""
    return c in OPERATORS

def is_separator(c):
    """Check if a character is a separator."""
    return c in SEPARATORS

def is_digit(c):
    """Check if a character is a digit."""
    return c.isdigit()

def is_identifier(c):
    """Check if a character is part of an identifier (alphanumeric or underscore)."""
    return c.isalnum() or c == '_'

def is_literal_char(c):
    """Check if a character is valid for a literal (numbers and string characters)."""
    return c.isdigit() or c in string.ascii_letters or c == '"'

def tokenize(code):
    """Tokenize the input code."""
    tokens = []
    i = 0
    n = len(code)
    current_token = ''
    in_string = False  # Track if we are inside a string literal
    
    while i < n:
        c = code[i]
        
        # Handle string literals
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
    
    # Add the last token if it exists
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

# Test the tokenizer
if __name__ == "__main__":
    # Sample input code snippet
    code = '''
    int main() {
        int x = 10;
        float y = 3.14;
        if (x > y) {
            return x + y;
        }
    }
    '''
    
    tokens = tokenize(code)
    for token in tokens:
        print(f'{token[0]}: {token[1]}')
