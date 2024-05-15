# CDataframe_tacca_tran
> ###### 2023-L1 EFREI TACCA Timothée, TRAN Kim-Lan


## Introduction

Spreadsheet programs such as LibreOffice Calc or MS Exceed are capable of sorting, displaying, calculating  data frames and much more. 

In python, a wide range of functions can be used to import, clean, analyse and visualise data. This flexibility is achieved through the use of a Pandas-specific data structure called "DataFrame", which is managed in a similar way to a spreadsheet in a spreadsheet application.

However, such a library is not available in the C language, which is why in this project we want to offer an alternative by developing a library written in the C language that can be used to implement some of the existing functions of Pandas.

‎ 

We decided to separate the project into branches. The `main` branch contains a simple ascii interface, while the `graphic_interface` branch uses special unicode characters and color codes

**⚠ Warning, some terminals are not capable of displaying these unicode characters or color codes, in this case, we invite you to directly use the `main` branch**


## Download

### Git clone
you can install the project using git clone :

```
git clone https://github.com/timotheetacca/CDataframe_tacca_tran.git
```
Or git clone the `graphic_interface` branch :
```
git clone -b graphic_interface https://github.com/timotheetacca/CDataframe_tacca_tran.git

```


### Install

You can also directly install the latest release of our project from [here](https://github.com/timotheetacca/CDataframe_tacca_tran) 

![download_cd](https://github.com/timotheetacca/CDataframe_tacca_tran/assets/66522009/f9067b4c-72d6-43ac-88a9-c637147a1cb0)

Ensure `main.c` is in the same directory as the other .c files and execute `main.c`.

![main_cd](https://github.com/timotheetacca/CDataframe_tacca_tran/assets/66522009/2b56d881-54fc-423b-b402-c0229a3197f5)

## Usage

After launching the program, you should find yourself in front of a list of orders, enter the order number in order to use it. 

All commands require the creation of a CDataframe, we recommend that you create it directly by executing command 1 from the start.

Our program uses dynamic arrays and is capable of performing the following commands:

* Create a new CDATAFRAME

* Fill a CDATAFRAME with data

* Hard fill a CDATAFRAME

* Display the contents of a CDATAFRAME

* Display a limited range of rows in a CDATAFRAME

* Display a limited range of columns in a CDATAFRAME

* Add a row to a CDATAFRAME

* Delete a row from a CDATAFRAME

* Add a column to a CDATAFRAME

* Delete a column from a CDATAFRAME

* Rename a column in a CDATAFRAME

* Check if a value exists in a CDATAFRAME

* Access a value in a CDATAFRAME

* Replace a value in a CDATAFRAME

* Display the number of rows in a CDATAFRAME

* Display the number of columns in a CDATAFRAME

* Display the names of columns in a CDATAFRAME

* Count cells in a CDATAFRAME based on a condition

* Sort a column

* Print a column by index

* Erase index of a column

* Check if index exists in a column

* Update index of a column

* Search for a value in a column


Some functions are not referenced in the list because they were created to be used in a function. If you want to use them, we invite you to directly modify the `main.c`

## Feedback

If you have any feedback, please reach out to us at timothee.tacca@efrei.net, kim-lan.tran@efrei.net
