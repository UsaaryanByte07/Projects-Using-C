# generate_structure.py
import os

def generate_tree(path=".", prefix=""):
    contents = sorted(os.listdir(path))
    pointers = ["├── "] * (len(contents) - 1) + ["└── "]
    for pointer, name in zip(pointers, contents):
        if name in [".git", "__pycache__", "node_modules", ".github"]:
            continue
        print(prefix + pointer + name)
        full_path = os.path.join(path, name)
        if os.path.isdir(full_path):
            extension = "│   " if pointer == "├── " else "    "
            generate_tree(full_path, prefix + extension)

if __name__ == "__main__":
    print("```")
    print("Projects-Using-C")
    generate_tree(".")
    print("```")