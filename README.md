# CS-210

<!DOCTYPE html>
<html>
  <body>
    <h1>[About]</h1>
    <p>
      This is the project for module seven of CS-210, the Corner Grocer's Grocery Tracking Program.
      <br>
      The program presents a menu to the user with options to do the following:
      <ul>
        <li>Produce a list of items purchased for a given day (including quantity), as indicated by the input file</li>
        <li>Show how many time sa specific item was purchased in a given day</li>
        <li>Print a text-based histogram of the list of items purchased for a given day</li>
      </ul>
    </p>
    <h1>[Compilation Instructions]</h1>
    <p>
      This was compiled using g++ 8.3.0-1 and python-dev 2.7.16-1 on Debian 10.9.
      </br>
      $: <code>g++ $(python-config --cflags --ldflags) Menu.cpp -o groceryTracking</code>
    </p>
    <h1>[8-1 Journal Q&A]</h1>
    <h3>Summarize the project and what problem it was solving.</h3>
    <p>
       This project solves the problem of tracking grocery purchases on a given day for the Corner Grocer's store.
       The purpose is to demonstrate the capabilities one might have when combining both C++ and Python to write a program.
       By completing this project, one is demonstrating the ability to write C++ code that can interface with Python code.
    </p>
    <h3>What did you do particularly well?</h3>
    <p>
       I believe my Python functions were written in a clear, concise, and efficient manner.
       While efforts were made to ensure the main C++ program was written as concisely as possible, the Python code stood out in this regard.
    </p>
    <h3>Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?</h3>
    <p>
       The main C++ program could be enhanced by including additional checks around potential failures.
       In hindsight, the failures I defined may not be an exhaustive list.
       The code could likely be made cleaner by reviewing the initialization and cleanup stages for the Python interpreter and associated values.
    </p>
    <h3>Which pieces of code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support?</h3>
    <p>
       The biggest challening in writing this assignment was passing values to and from C++ to Python.
       I was able to overcome this challenge by utilizing the starter reference code, the Python documentation, and print statements.
       Specifcally, the call to "Py_BuildValue" in the starter code made me realize I was not correctly passing the value from C++ to Python.
       The Python documentation, in particular the "Python/C API Reference Manual", was very helpful when it came to understanding the necessary function calls.
       Print statements were helpful for seeing the value of variables as they made it through the execution of the program.
    </p>
    <h3>What skills from this project will be particularly transferable to other projects or course work?</h3>
    <p>
       The most valuable and transferable skill from this project is the skill of reading through official documentation to find information.
       This will undoubtedly be extremely useful moving forward, especially as courses become more difficult.
       Another valuable skill would be understanding and using APIs to extend code.
       Additionally, this project was a very good opportunity to practice troubleshooting skills.
    </p>
    <h3>How did you make this program maintainable, readable, and adaptable?</h3>
    <p>
       I made this program maintainable by keeping the logic as organized as possible.
       Different pieces of logic were separated from the main program in an effort to reduce the time spent deciding where a change should go.
       The program was made readable by using descriptive variable names, replacing "magic numbers" with constants, and including comments where appropriate.
       Adaptability for this program comes from the organization. I made a best effort to take code that would be reused and separate it from the main program.
    </p>
  </body>
</html>
