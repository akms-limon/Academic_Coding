import re

token_specification = [
    ('Keyword', r'\b(int|float|return|if|else|while|for|do|break|continue|void|char|double)\b'),
    ('Identifier', r'[a-zA-Z_][a-zA-Z0-9_]*'), 
    ('Float', r'\b\d+\.\d*([eE][+-]?\d+)?\b'),
    ('Integer', r'\b\d+\b'), 
    ('Operator', r'[-+*/%=!<>]+'),
    ('separator', r'[;{},()]'), 
    ('String', r'"([^"\\]*(\\.[^"\\]*)*)?"'),
    ('Char', r"'([^'\\]*(\\.[^'\\]*)*)?'"),
    ('Whitespace', r'\s+'),
]

token_regex = '|'.join(f'(?P<{name}>{pattern})' for name, pattern in token_specification)
token_pattern = re.compile(token_regex)

def tokenize(code):
    tokens = []
    for match in token_pattern.finditer(code):
        token_type = match.lastgroup
        token_value = match.group(token_type)
        if token_type != 'Whitespace': 
            tokens.append(f'{token_value} ({token_type})')
    return tokens

code = open('test.txt').read()
tokens = tokenize(code)

for token in tokens:
    print(token)
