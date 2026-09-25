import os
import glob
import re
import subprocess

lab_dir = "/Users/bhaskar/Coding/Practice/CPP/Sem3/ObjectOrientedProgramming/LabCopy"
pdf_util_dir = os.path.join(lab_dir, "pdfUtil")
cpp_files = sorted([f for f in glob.glob(os.path.join(lab_dir, "*.cpp"))])

# Pre-defined realistic interactive execution transcripts for console output
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

    "03-ShoppingCart.cpp": """$ ./03-ShoppingCart

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

    "04-TimeAddition.cpp": """$ ./04-TimeAddition
Enter hours and minutes: 2 45
Enter hours and minutes: 3 30
Time 1: 2 hrs 45 mins
Time 2: 3 hrs 30 mins
Sum: 6 hrs 15 mins""",

    "05-CurrencyFriendFunction.cpp": """$ ./05-CurrencyFriendFunction
$50 is greater than Rs. 4500""",

    "06-ComplexNumbersConstructors.cpp": """$ ./06-ComplexNumbersConstructors
0 + 0i : created by Default constructor
3 + 4i : created by Parameterized constructor
3 + 4i : created by Copy constructor""",

    "07-StaticMembers.cpp": """$ ./07-StaticMembers
Roll no.1 : Ayush
Roll no.2 : Bipin
Students: 2
Roll no.3 : Gaurav
Students: 3
Left the Gaurav block.
Students: 2""",

    "08-DynamicArrayAllocation.cpp": """$ ./08-DynamicArrayAllocation
Enter number of elements: 2
Enter real and imag for number 1: 3 4
Enter real and imag for number 2: 5 -2

Complex Numbers:
3 + 4i
5 + -2i""",

    "09-ThisPointerComparison.cpp": """$ ./09-ThisPointerComparison
Older: Bob (25)""",

    "10-UnaryOperatorOverloading.cpp": """$ ./10-UnaryOperatorOverloading
Original: 3 + -4i
Negated: -3 + 4i""",

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

# Program Titles for the Index table
titles = {
    "01-FunctionOverloading.cpp": "Volume Calculation using Function Overloading",
    "02-BankAccount.cpp": "Bank Account Class Implementation",
    "03-ShoppingCart.cpp": "Shopping Cart using Static Variables & Switch Cases",
    "04-TimeAddition.cpp": "Time Addition by Passing and Returning Objects",
    "05-CurrencyFriendFunction.cpp": "Currency Comparison using Friend Function",
    "06-ComplexNumbersConstructors.cpp": "Complex Numbers with Constructor Overloading",
    "07-StaticMembers.cpp": "Static Data Members and Member Functions",
    "08-DynamicArrayAllocation.cpp": "Dynamic Memory Allocation for Array of Objects",
    "09-ThisPointerComparison.cpp": "Object Comparison using 'this' Pointer",
    "10-UnaryOperatorOverloading.cpp": "Unary Operator Overloading (Minus Operator)",
    "11-PrefixPostfixOperators.cpp": "Prefix and Postfix Operator Overloading",
    "12-StreamOperatorOverloading.cpp": "Stream Insertion and Extraction Operators",
    "13-TypeConversion.cpp": "Four-Way User-Defined Data Type Conversions"
}

programs = []

for idx, fpath in enumerate(cpp_files, 1):
    fname = os.path.basename(fpath)
    with open(fpath, "r", encoding="utf-8") as f:
        content = f.read()

    # Extract Question comment from top
    lines = content.splitlines()
    q_lines = []
    code_lines = []
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
            code_lines.append(l)

    q_text = " ".join(q_lines)
    code_text = content.strip() # Exact code as in the file

    output_text = sample_runs.get(fname, "")

    programs.append({
        "num": idx,
        "fname": fname,
        "title": titles.get(fname, fname),
        "question": q_text,
        "code": code_text,
        "output": output_text
    })

print(f"Processed {len(programs)} programs.")
