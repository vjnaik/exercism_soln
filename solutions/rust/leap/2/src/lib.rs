pub fn is_leap_year(year: u64) -> bool {
    //(year % 400 == 0) || !(year % 100 == 0) && (year % 4 == 0)
    match year {
        _ if year.is_multiple_of(400) => true,
        _ if !year.is_multiple_of(400) && year.is_multiple_of(100) => false,
        _ if year.is_multiple_of(4) => true,
        _ => false
    }
}