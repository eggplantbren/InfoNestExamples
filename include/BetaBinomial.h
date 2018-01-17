#ifndef InfoNestExamples_BetaBinomial_h
#define InfoNestExamples_BetaBinomial_h

#include <cstdlib>
#include <RNG.h>

namespace InfoNestExamples
{

class BetaBinomial
{
    private:
        // Number of binomial trials
        static constexpr size_t N = 100;

        // Success probability parameter
        double theta;

        // Number of successes
        unsigned int x;

    public:
        // Do-nothing constructor
        BetaBinomial();

        // Generate from the distribution
        void generate(InfoNest::RNG& rng);

        // Metropolis proposal
        double perturb(InfoNest::RNG& rng);

        // Printing to stream
        void print(std::ostream& out) const;

    public:
        // A few options to use for `distance`
        static double parameter_distance(const BetaBinomial& b1,
                                         const BetaBinomial& b2);
        static double data_distance(const BetaBinomial& b1,
                                    const BetaBinomial& b2);
        static double joint_distance(const BetaBinomial& b1,
                                     const BetaBinomial& b2);


};

} // namespace InfoNestExamples

#endif

