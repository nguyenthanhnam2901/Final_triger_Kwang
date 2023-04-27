bool isValidNumberOfStudents(int n) 
{
    if (n < 0 || n > 1000) 
    {
        return false;
    }
    return true;
}


bool isDuplicateID(student students[], int n, char id[]) {
    for (int i = 1; i < n; ++i) {
        if (strcmp(students[i].id, id) == 0) {
            return true;
        }
    }
    return false;
}

bool isValidBirthdate(int day, int month, int year) {
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1) {
        return false;
    }
    return true;
}

bool isValidGrade(float grade[]) {
    for (int i = 0; i < 3; ++i) {
        if (grade[i] < 0 || grade[i] > 20) {
            return false;
        }
    }
    return true;
}
