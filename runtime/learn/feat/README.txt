
---- PARAMETER ENCODER GENERALIZATION

Currently, all app parameter encodings that encode numeric parameters in tasks are based on a default log tile coder.

TODO:
Let them be numeric by default on a rescale (lin/log).
ANN input layer will be in general a combination of features of different formats (tile coders/num coders)
Some coders will be the same (builtin: appcall, depth), but app param coders should be flexible enough to be defined by the user eg
[[steel::feat("VARNAME", numeric, log)]]
[[steel::feat("VARNAME", numeric, linear)]]
[[steel::feat("VARNAME", tile, log)]]
[[steel::feat("VARNAME", tile, linear)]]

Which will be converted to specific types in the corresponding app::impl traits in App.Graph module

Then, the ANN input layer will be like more generic:

template <typename... EncoderTs>
class activations : protected activation<EncoderTs> ... { stuff };

and its output via an ANN matrix will be customized at compile-time.


