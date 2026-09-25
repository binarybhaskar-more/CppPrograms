import os
import glob
import re
import subprocess

lab_dir = "/Users/bhaskar/Coding/Practice/CPP/Sem3/ObjectOrientedProgramming/LabCopy"
pdf_util_dir = os.path.join(lab_dir, "pdfUtil")
os.makedirs(pdf_util_dir, exist_ok=True)

cpp_files = sorted([f for f in glob.glob(os.path.join(lab_dir, "*.cpp"))])

sample_runs = {
    "01-FunctionOverloading.cpp": """$ ./01-FunctionOverloading
Enter side of cube: 5
Volume of cube: 125
Enter radius and height of cylinder: 3 7
Volume of cylinder: 197.82
Enter length, breadth and height of cuboid: 2 3 4
Volume of cuboid: 24""",

    "02-BankAccount.cpp": """$ ./02-BankAccount
Depositing: 1500
Name: Additya
Balance: 6500
Withdrawing: 2000
Name: Additya
Balance: 4500""",

    "03-TimeAddition.cpp": """$ ./03-TimeAddition
Enter hours and minutes: 2 45
Enter hours and minutes: 3 30
Time 1: 2 hrs 45 mins
Time 2: 3 hrs 30 mins
Sum: 6 hrs 15 mins""",

    "04-CurrencyFriendFunction.cpp": """$ ./04-CurrencyFriendFunction
$50 is greater than Rs. 4500""",

    "05-ComplexNumbersConstructors.cpp": """$ ./05-ComplexNumbersConstructors
0 + 0i : created by Default constructor
3 + 4i : created by Parameterized constructor
3 + 4i : created by Copy constructor""",

    "06-StaticMembers.cpp": """$ ./06-StaticMembers
Roll no.1 : Ayush
Roll no.2 : Bipin
Students: 2
Roll no.3 : Gaurav
Students: 3
Left the Gaurav block.
Students: 2""",

    "07-ShoppingCart.cpp": """$ ./07-ShoppingCart

0. Initialise cart
1. Add Item
2. Remove Item
3. Show Bill
4. Clear Cart
5. Exit
Enter choice: 1
Enter item code, name, and price: 101 Pen 15
Enter quantity: 2

0. Initialise cart
1. Add Item
2. Remove Item
3. Show Bill
4. Clear Cart
5. Exit
Enter choice: 1
Enter item code, name, and price: 102 Notebook 50
Enter quantity: 3

0. Initialise cart
1. Add Item
2. Remove Item
3. Show Bill
4. Clear Cart
5. Exit
Enter choice: 3
Code	Name	Price	Qty	Total
101	Pen	15	2	30
102	Notebook	50	3	150
Total Bill: 180

0. Initialise cart
1. Add Item
2. Remove Item
3. Show Bill
4. Clear Cart
5. Exit
Enter choice: 2
Enter item code to remove: 101
Enter quantity to remove: 1

0. Initialise cart
1. Add Item
2. Remove Item
3. Show Bill
4. Clear Cart
5. Exit
Enter choice: 3
Code	Name	Price	Qty	Total
101	Pen	15	1	15
102	Notebook	50	3	150
Total Bill: 165

0. Initialise cart
1. Add Item
2. Remove Item
3. Show Bill
4. Clear Cart
5. Exit
Enter choice: 5""",

    "08-DynamicArrayAllocation.cpp": """$ ./08-DynamicArrayAllocation
Enter number of elements: 2
Enter real and imag for number 1: 3 4
Enter real and imag for number 2: 5 -2

Complex Numbers:
3 + 4i
5 + -2i""",

    "09-ThisPointerComparison.cpp": """$ ./09-ThisPointerComparison
Older: Bob (25)""",

    "10-OperatorOverloading.cpp": """$ ./10-OperatorOverloading
c1: 5 + 3i
c2: 2 + 4i
c1 + c2: 7 + 7i
c1 - c2: 3 + -1i
-c1: -5 + -3i""",

    "11-PrefixPostfixOperators.cpp": """$ ./11-PrefixPostfixOperators
Prefix ++: Page: 11
Postfix ++: Page: 12
Prefix --: Page: 11
Postfix --: Page: 10""",

    "12-StreamOperatorOverloading.cpp": """$ ./12-StreamOperatorOverloading
Enter hours, minutes, and seconds: 10 25 45
Time: 10h 25m 45s""",

    "13-TypeConversion.cpp": """$ ./13-TypeConversion
Predefined to User-defined (Constructor): 135 mins
User-defined to Predefined (Operator): 135
User-defined to User-defined (Constructor): 2 hrs 15 mins
User-defined to User-defined (Operator): 150 mins"""
}

titles = {
    "01-FunctionOverloading.cpp": "Function Overloading for Volume Calculation (Cube, Cylinder, Cuboid)",
    "02-BankAccount.cpp": "Class Representation of Bank Account Management",
    "03-TimeAddition.cpp": "Addition of Time Objects by Passing and Returning Objects",
    "04-CurrencyFriendFunction.cpp": "Currency Comparison (USD & INR) using Friend Function",
    "05-ComplexNumbersConstructors.cpp": "Complex Numbers with Constructor Overloading",
    "06-StaticMembers.cpp": "Static Data Members and Member Functions for Object Tracking",
    "07-ShoppingCart.cpp": "Menu-Driven Shopping Cart with Static Data Members & Switch Cases",
    "08-DynamicArrayAllocation.cpp": "Dynamic Memory Allocation for Array of Objects using 'new' and 'delete'",
    "09-ThisPointerComparison.cpp": "Object Comparison and Returning Invoking Object using 'this' Pointer",
    "10-OperatorOverloading.cpp": "Operator Overloading (Unary '-' and Binary '+', '-')",
    "11-PrefixPostfixOperators.cpp": "Prefix and Postfix Unary Operators (++ and --) Overloading",
    "12-StreamOperatorOverloading.cpp": "Stream Insertion (<<) and Extraction (>>) Operator Overloading",
    "13-TypeConversion.cpp": "Four-Way User-Defined Data Type Conversions"
}

programs = []

for idx, fpath in enumerate(cpp_files, 1):
    fname = os.path.basename(fpath)
    with open(fpath, "r", encoding="utf-8") as f:
        content = f.read()

    lines = content.splitlines()
    q_lines = []
    is_q = True
    for l in lines:
        if is_q and l.strip().startswith("//"):
            text = re.sub(r"^//\s*(Question:\s*)?", "", l.strip())
            if text:
                q_lines.append(text)
        elif is_q and not l.strip():
            continue
        else:
            is_q = False

    q_text = " ".join(q_lines)

    programs.append({
        "num": idx,
        "fname": fname,
        "title": titles.get(fname, fname),
        "question": q_text,
        "code": content.strip(),
        "output": sample_runs.get(fname, "")
    })

typ_content = []

typ_content.append("""
#set page(
  paper: "a4",
  margin: (top: 1.6cm, bottom: 1.6cm, left: 1.8cm, right: 1.8cm),
  header: context [
    #if counter(page).get().first() > 1 [
      #grid(
        columns: (1fr, 1fr),
        align: (left, right),
        text(size: 8.5pt, fill: rgb("#555555"), font: "Times New Roman")[Object Oriented Programming (C++) Lab],
        text(size: 8.5pt, fill: rgb("#555555"), font: "Times New Roman")[Practical Assignments Report]
      )
      #v(-6pt)
      #line(length: 100%, stroke: 0.5pt + rgb("#cccccc"))
    ]
  ],
  footer: context [
    #line(length: 100%, stroke: 0.5pt + rgb("#cccccc"))
    #v(2pt)
    #align(center)[
      #text(size: 9pt, fill: rgb("#444444"), font: "Times New Roman")[
        Page #counter(page).display() of #counter(page).final().first()
      ]
    ]
  ]
)

#set text(
  font: "Times New Roman",
  size: 10pt,
  lang: "en"
)

#set par(justify: true, leading: 0.5em)

// Code block styling
#show raw.where(block: true): it => {
  if it.lang == "cpp" [
    #block(
      fill: rgb("#fcfcfc"),
      stroke: 0.5pt + rgb("#d1d5db"),
      inset: (x: 8pt, y: 6pt),
      radius: 3pt,
      width: 100%,
      clip: true,
      text(font: ("Menlo", "Courier New"), size: 7.3pt, it)
    )
  ] else [
    #block(
      fill: rgb("#1e293b"),
      stroke: 0.5pt + rgb("#0f172a"),
      inset: (x: 8pt, y: 6pt),
      radius: 3pt,
      width: 100%,
      clip: true,
      text(font: ("Menlo", "Courier New"), size: 7.2pt, fill: rgb("#f8fafc"), it)
    )
  ]
}

// Inline code
#show raw.where(block: false): it => text(
  font: ("Menlo", "Courier New"),
  size: 8.5pt,
  fill: rgb("#991b1b"),
  it
)
""")

# INDEX PAGE (Page 1)
typ_content.append("""
#align(center)[
  #v(0.2cm)
  #text(size: 17pt, weight: "bold", font: "Times New Roman")[INDEX OF PRACTICALS]
  #v(-4pt)
  #text(size: 10.5pt, style: "italic", fill: rgb("#475569"))[Object Oriented Programming Lab (C++)]
  #v(0.3cm)
]

#table(
  columns: (32pt, 1fr, 52pt, 65pt),
  align: (center + horizon, left + horizon, center + horizon, center + horizon),
  stroke: (x, y) => if y == 0 {
    (bottom: 1.5pt + rgb("#1e293b"), top: 1.5pt + rgb("#1e293b"))
  } else {
    0.5pt + rgb("#e2e8f0")
  },
  fill: (x, y) => if y == 0 {
    rgb("#f8fafc")
  } else if calc.even(y) {
    rgb("#f8fafc")
  } else {
    white
  },
  table.header(
    [*S.No.*],
    [*Problem Title / Practical Description*],
    [*Page*],
    [*Remarks*]
  ),
""")

for p in programs:
    num = p["num"]
    title = p["title"].replace("&", "\\&")
    typ_content.append(f'  [{num}], [{title}], context counter(page).at(<prog{num}>).first(), [],\n')

typ_content.append(")\n\n")

# PROGRAM ENTRIES
for p in programs:
    num = p["num"]
    title = p["title"].replace("&", "\\&")
    q_text = p["question"].replace("&", "\\&").replace("$", "\\$")
    code_text = p["code"]
    out_text = p["output"]

    typ_content.append("#pagebreak()\n")
    typ_content.append(f'= Practical / Question No. {num} <prog{num}>\n')
    typ_content.append(f'#v(-4pt)\n')
    typ_content.append(f'#text(size: 10.5pt, weight: "semibold", fill: rgb("#1e3a8a"))[{title}]\n\n')

    # Question Box
    typ_content.append(f"""#block(
  fill: rgb("#f1f5f9"),
  stroke: 0.8pt + rgb("#cbd5e1"),
  inset: (x: 8pt, y: 6pt),
  radius: 3pt,
  width: 100%,
)[
  #text(weight: "bold", fill: rgb("#0f172a"))[Question:] #h(3pt)
  #text(fill: rgb("#1e293b"))[{q_text}]
]

#v(2pt)
#text(size: 10pt, weight: "bold", fill: rgb("#0f172a"))[Source Code:]

```cpp
{code_text}
```

#v(2pt)
#block(breakable: false, width: 100%)[
  #text(size: 10pt, weight: "bold", fill: rgb("#0f172a"))[Example Output:]
  ```text
{out_text}
  ```
]
""")

output_typ_path = os.path.join(pdf_util_dir, "lab_report.typ")
with open(output_typ_path, "w", encoding="utf-8") as f:
    f.write("".join(typ_content))

print(f"Generated Typst source at: {output_typ_path}")

pdf_output_path = os.path.join(lab_dir, "OOP_Lab_Assignments.pdf")
cmd = ["/opt/homebrew/bin/typst", "compile", output_typ_path, pdf_output_path]
res = subprocess.run(cmd, capture_output=True, text=True)

if res.returncode == 0:
    print(f"Successfully compiled PDF to: {pdf_output_path}")
else:
    print("Compilation error:")
    print(res.stderr)
