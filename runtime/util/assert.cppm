
export module SteelRT.Util.Assert;

export
namespace safe {

void assert_fail(const char * assertion, const char * file, unsigned line, const char * func);

} // namespace safe
