// Config
bool DEBUG = true;
std::string JUDGE_HOME = "/usr/local/judge_runner";
const char * COMPILE_C[] = {"gcc", "main.c", "-o", "main", NULL};

#define LANG_C 0
#define LANG_CPP 1
#define LANG_JAVA 2
#define LANG_PYTHON 3

#define MEGABYTE 1024*1024
#define MAX_FILE_SIZE 32
#define MAX_STACK_SIZE 64

// Global variable
std::string working_dir;

// Solution data
int solution_id = 0;
int lang = 0;

void _log(std::string s) {
    if (DEBUG) {
        std::cout << s << std::endl;
    }
}

bool _dir_exist(const std::string &path) {
    DIR *dp;
    if ((dp = opendir(path.c_str())) == NULL) return false;
    closedir(dp);
    return true;
}

void _copy_file(const std::string &source, const std::string &target) {
    system(("cp " + source + " " + target).c_str());
}

size_t _get_filesize(std::string filename) {
    struct stat st;
    if(stat(filename.c_str(), &st) != 0) {
        return 0;
    }
    return st.st_size;   
}