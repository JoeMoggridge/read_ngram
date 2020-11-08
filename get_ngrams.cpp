#include <Rcpp.h>
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <vector>


using namespace Rcpp;
using namespace std;

// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::export]]

vector<string> get_ngrams(std::string filename)
{
    //1. open input file
    ifstream input_file(filename, ifstream::in);
    if (!input_file.is_open())
    {
        throw std::range_error("File does not exist");
    }

    //2.  read in ngram
    string ngram;
    list<string> output;
    while (getline(input_file, ngram)) 
    {
        //get only the ngram from each line, discard all the number information.
        string word = ngram.substr(0, ngram.find("\t"));

        if (word.length > 0)
        {
            boost::to_lower(word);
            output.push_back(word);
        }
    }

    //3. convert output to vector and return
    vector<string> result(output.begin(), output.end());
    return result;

}
