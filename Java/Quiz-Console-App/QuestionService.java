import java.util.Scanner;

public class QuestionService {

    Question[] question = new Question[5];
    String[] ans = new String[5];

    QuestionService(){
        question[0] = new Question(1, "What is the time complexity of binary search?",
                "1. O(n)", "2. O(log n)", "3. O(n log n)", "4. O(1)", "2. O(log n)");

        question[1]  = new Question(2, "Which data structure is used in recursion?",
                "1. Queue", "2. Stack", "3. Linked List", "4. Heap", "2. Stack");

        question[2]  = new Question(3, "Which of the following sorting algorithms is NOT stable?",
                "1. Merge Sort", "2. Bubble Sort", "3. Quick Sort", "4. Insertion Sort", "3. Quick Sort");

        question[3]  = new Question(4, "What does JVM stand for in Java?",
                "1. Java Virtual Machine", "2. Java Variable Method", "3. Java Verified Mode", "4. Just Visual Model", "1. Java Virtual Machine");

        question[4]  = new Question(5, "Which of the following is NOT a Java feature?",
                "1. Object-Oriented", "2. Platform Dependent", "3. Multithreaded", "4. Robust", "2. Platform Dependent");
    }

    void playQuiz(){

        for(int i = 0; i<question.length; i++){
            System.out.println("Question "+question[i].getId());
            System.out.println(question[i].getQuestion());
            System.out.println(question[i].getOpt1());
            System.out.println(question[i].getOpt2());
            System.out.println(question[i].getOpt3());
            System.out.println(question[i].getOpt4());

            Scanner scanner = new Scanner(System.in);
            String input = scanner.nextLine();
            ans[i] = input;
        }
    }

    void CalculateScore(){
        int score = 0;
        for(int i = 0; i<ans.length; i++){
            char correctOption = question[i].getAnswer().charAt(0);
            char optionMarked = ans[i].charAt(0);

            if(correctOption == optionMarked){
                score++;
            }
        }

        System.out.println("Total Score of the user is " + score + " out of 5");
    }

}
