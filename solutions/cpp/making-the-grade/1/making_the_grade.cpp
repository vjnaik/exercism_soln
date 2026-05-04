#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> result;
    for (auto score: student_scores) {
        result.push_back(score);
    }
    return result;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    int count = 0;
    for (auto score: student_scores) {
        if (score <= 40) { count++; }
    }
    return count;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    int interval = (highest_score - 40) / 4;
    std::array<int, 4> grade_threshold;
    for (size_t i = 0; i < grade_threshold.size(); i++) {
        grade_threshold[i] = 41 + i * interval;
    }
    return grade_threshold;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<std::string> result_string;
    for (size_t i = 0; i < student_scores.size(); i++) {
        std::string entry = std::to_string(i + 1) + ". " + 
                            student_names[i] + ": " +
                            std::to_string(student_scores[i]);
        result_string.push_back(entry);
    }
    return result_string;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    for (size_t i = 0; i < student_scores.size(); i++) {
        if (student_scores[i] == 100) { return student_names[i]; }
    }
    return "";
}
