# update_readme.py
start = "<!-- START_STRUCTURE -->"
end = "<!-- END_STRUCTURE -->"

# Read README.md
with open("README.md", "r", encoding="utf-8") as f:
    readme = f.read()

# Generate new structure
import subprocess
structure = subprocess.getoutput("python generate_structure.py")

# Replace content between markers
before = readme.split(start)[0] + start + "\n"
after = "\n" + end + readme.split(end)[1]
new_readme = before + structure + after

# Write updated README.md
with open("README.md", "w", encoding="utf-8") as f:
    f.write(new_readme)
