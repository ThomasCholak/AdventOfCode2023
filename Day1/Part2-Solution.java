import java.io.File;
import java.io.FileReader;
import java.util.HashMap;
import java.util.Map;
import java.io.BufferedReader;
import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) throws Exception
    {
        int result_int;
        String result;

        List<Integer> total_list = new ArrayList<>();  // initialize list for storing integers from each line

        // have to replace so that previous number isn't 'burnt'
        // https://www.reddit.com/r/adventofcode/comments/1883ibu/comment/kbielt0/?utm_source=share&utm_medium=web3x&utm_name=web3xcss&utm_term=1&utm_content=share_button
        Map<String, String> num_replace = new HashMap<>();
        num_replace.put("one", "one1one");
        num_replace.put("two", "two2two");
        num_replace.put("three", "three3three");
        num_replace.put("four", "four4four");
        num_replace.put("five", "five5five");
        num_replace.put("six", "six6six");
        num_replace.put("seven", "seven7seven");
        num_replace.put("eight", "eight8eight");
        num_replace.put("nine", "nine9nine");

        File file = new File("input.txt");  // opens file 'input.txt' (must name input file the same)

        BufferedReader br = new BufferedReader(new FileReader(file));
        String in_line = null;

        while ((in_line = br.readLine()) != null)
        {
            StringBuilder sb = new StringBuilder();
            String line = replace_Val(in_line, num_replace);

            for (int i = line.length() - 1; i >= 0; i --)  // grabs last digit of string 'line'
            {
                char c = line.charAt(i);
                if (Character.isDigit(c))
                {
                    sb.insert(0, c);
                    break;
                }
            }

            for (int i = 0; i < line.length(); i++)       // grabs first digit of string 'line'
            {
                char c = line.charAt(i);
                if (Character.isDigit(c))
                {
                    sb.insert(0, c);
                    break;
                }
            }

            result = sb.toString();                 // concats first and last digit to a string
            result_int = Integer.parseInt(result);  // converts string 'results' into integers
            total_list.add(result_int);
        }
        int sum = 0;

        for (Integer integer : total_list) sum += integer;  // for-loop to find sum of 'total_sum' list
        System.out.printf("Sum -> %d",sum);                 // PRINTS sum of '55429' (The correct answer for my data set)
    }
    
    // REPLACES string values using 'num_replace' dictionary values
    // https://www.geeksforgeeks.org/hashmap-replacekey-value-method-in-java-with-examples/
    public static String replace_Val(String in_str, Map<String, String> replace_value)
    {
        for (Map.Entry<String, String> values : replace_value.entrySet())
        {
            String word = values.getKey();                // grabs word to be replaced
            String num_value = values.getValue();         // replaces word with new string "as per dictionary"

            in_str = in_str.replaceAll(word, num_value);  // constructs new string utilizing new values
        }

        return in_str;  // returns new 'input' string
    }
}
