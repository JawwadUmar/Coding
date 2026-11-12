
def flatten_dict(d, parent_key = ""):
    result = {}

    for key,value in d.items():
        new_key = ""
        if(parent_key):
            new_key = parent_key + "." + key
        else:
            new_key = key

        if isinstance(value, dict):
            result.update(flatten_dict(value, new_key))
        else:
            result.update({new_key: value})

    return result

data = {"a": {"b": 1, "c": {"d": 2}}, "e": 3}

print(flatten_dict(data))