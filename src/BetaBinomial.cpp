#include "BetaBinomial.h"
#include "Utils.h"
#include <cmath>

namespace InfoNestExamples
{

BetaBinomial::BetaBinomial()
{

}

void BetaBinomial::compute_logl()
{
    // Coefficient
    logl = std::lgamma(N+1) - std::lgamma(x+1) - std::lgamma(N-x+1);

    // Other part
    logl += x*log(theta) + (N-x)*log(1.0 - theta);
}


// Generate from the distribution
void BetaBinomial::generate(InfoNest::RNG& rng)
{
    theta = rng.rand();
    x = 0;
    for(size_t i=0; i<N; ++i)
        if(rng.rand() <= theta)
            ++x;
}


// Metropolis proposal
double BetaBinomial::perturb(InfoNest::RNG& rng)
{
    double logH = -logl;

    theta += rng.randh();
    InfoNest::wrap(theta, 0.0, 1.0);

    logH += logl;

    return logH;
}


// Printing to stream
void BetaBinomial::print(std::ostream& out) const
{
    out << theta;
}


//    public:
//        // A few options to use for `distance`
double BetaBinomial::parameter_distance(const BetaBinomial& b1,
                                        const BetaBinomial& b2)
{
    return std::abs(b2.get_theta() - b1.get_theta());
}

} // namespace InfoNestExamples

