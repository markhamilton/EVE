# Copy the header files to the distribution directory

cd sources
find . -type d -exec mkdir -p ../../output/include/{} \;
find . -name "*.h" -exec cp {} ../../output/include/{} \;

# Copy the examples to the distribution directory

cd ../examples/atmo
mkdir -p ../../../output/examples/atmo/atmo
find . ! \( -name "*.cbp" -o -name "*.depend" -o -name "*.layout" -o -name "*.raw" -o -name "log.html" \) -exec cp {} ../../../output/examples/atmo/atmo/{} \;

# Generate the Doxygen documentation

cd ../../doc
mkdir -p ../../output/doc
doxygen
