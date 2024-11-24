def find_key(func_decl, end_pos):
    key_list = {'string': 6, 'int': 3, 'float': 5, 'double': 6}
    for key, lent in key_list.items():
        pos = func_decl.find(key, 0, end_pos)
        if pos != -1:
            return pos + lent
    return -1

def find_and_remove_inline_function(code):
    
    inline_pos = code.find("inline")
    if inline_pos == -1:
        return code, None


    start = code.find("{", inline_pos) + 1
    end = code.find("}", start)
    
    function_text = code[inline_pos:end + 1]

    # name_start = function_text.find("int") + 3
    name_end = function_text.find("(")
    name_start = find_key(function_text, name_end)
    if name_start == -1: return (code, None)
    func_name = function_text[name_start:name_end].strip()

    param_start = name_end + 1
    param_end = function_text.find(")", param_start)
    params = function_text[param_start:param_end].split(",")
    params = [p.split()[-1].strip() for p in params] 

    body = function_text[function_text.find("{") + 1:function_text.find("}")].strip()
    if body.startswith("return "): 
        body = body[7:].strip()

    code = code.replace(function_text, "")

    return code, {"name": func_name, "params": params, "body": body}


def replace_inline_calls(code, function_details):
    if function_details is None:
        return code 

    func_name = function_details["name"]
    params = function_details["params"]
    body = function_details["body"]

    while True:
        call_start = code.find(f"{func_name}(")
        if call_start == -1:
            break  

        call_end = code.find(");", call_start)

        arg_string = code[call_start + len(func_name) + 1:call_end]
        args = [arg.strip() for arg in arg_string.split(",")]

        expanded_body = body
        for param, arg in zip(params, args):
            expanded_body = expanded_body.replace(param, arg)

        code = code[:call_start] + expanded_body + code[call_end + 2:]

    return code


def preprocess_code(code):
    code, function_details = find_and_remove_inline_function(code)
    code = replace_inline_calls(code, function_details)
    return code


cpp_code = open('inline_test.txt').read()

updated_code = preprocess_code(cpp_code)

print("Updated C++ Code:\n")
print(updated_code)
