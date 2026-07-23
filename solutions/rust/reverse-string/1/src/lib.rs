pub fn reverse(input: &str) -> String {
    input.chars()              // Split into characters
         .rev()                // Reverse the characters
         .collect::<String>()  // Collect into a String
}