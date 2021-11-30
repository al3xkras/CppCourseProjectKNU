#ifndef CPPCOURSEPROJECTKNU_TESTCASE_CPP
#define CPPCOURSEPROJECTKNU_TESTCASE_CPP

#include <iostream>
#include <sstream>
#include <set>



class TestCase {
private:
    std::string testClassName;
    std::string testName;

    std::ostream &log;
    std::ostream &err;

    void printTestContext(std::ostream &os){
        os << testClassName << ", \""<<testName<<"\": ";
    }
    void testPassed(){
        printTestContext(log);
        log<<"test passed"<<std::endl;
    }
    void testFailed(){
        printTestContext(err);
        err<<"test failed"<<std::endl<<"    ";
    }
    void onTestEnd(bool passed){
        if (passed){
            log<<"\n\n";
            return;
        }
        err<<"\n\n\n";
    }

public:
    TestCase(std::string testClassName, std::string testName, std::ostream &log, std::ostream &err) :
            testClassName(std::move(testClassName)),testName(std::move(testName)) ,
            log(log), err(err) {
    }

    template<typename T>
    void assertEquals(T expected, T actual){
        if (expected==actual) {
            testPassed();
            onTestEnd(true);
            return;
        }

        testFailed();
        err<<"Expected: "<<expected<<", Actual: "<<actual;
        onTestEnd(false);
    }
};

class Test {
private:
    std::string testClassName;

    std::ostream &log;
    std::ostream &err;

    std::set<std::string> testNames;

public:
    Test(std::string testClassName, std::ostream &log, std::ostream &err) :
        testClassName(std::move(testClassName)),
        log(log), err(err) {
    }

    TestCase test(const std::string& name){
        if (testNames.count(name))
            throw std::runtime_error("Test \""+name+"\" already exists.");

        testNames.insert(name);

        return {testClassName,name,log,err};
    }
};


#endif //CPPCOURSEPROJECTKNU_TESTCASE_CPP
