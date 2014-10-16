       IDENTIFICATION DIVISION.
       PROGRAM-ID. mult.
       Author Jared Wallace
       DATA DIVISION.
       WORKING-sTORAGE SECTION.
       01 Num1 PIC 999V99 VALUE ZEROS.
       01 Num2 PIC 999V99 VALUE ZEROS.
       01 Result PIC 9(9)V99 VALUE ZEROS.
       PROCEDURE DIVISION.
       CalculateResult.
           DISPLAY "Enter two numbers".
           ACCEPT Num1.
           ACCEPT Num2.
           MULTIPLY Num1 BY Num2 GIVING Result.
           DISPLAY "Result is: ", Result.
       STOP RUN.
