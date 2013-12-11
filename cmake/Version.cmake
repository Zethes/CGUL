# CGUL uses a 3 digit versioning system.
# Major.Minor.Patch

# The MAJOR version is reserved for major milestones. The initial "official release" of CGUL will
# be version 1.0.0.
set(CGUL_VERSION_MAJOR 0)

# The MINOR version should be incremented when the API changes in a way that it could break
# applications already using CGUL.  The only exception here is any code that is marked
# EXPERIMENTAL.  All code in CGUL until the 0.2.0 release is considered EXPERIMENTAL.
set(CGUL_VERSION_MINOR 1)

# The PATCH version can be incremented whenever it is necessary.  The patch version should be
# incremented whenever there is a "release" in any form, but can also be incremented periodically
# for testing purposes.
set(CGUL_VERSION_PATCH 5)

# Combined version
set(CGUL_VERSION ${CGUL_VERSION_MAJOR}.${CGUL_VERSION_MINOR}.${CGUL_VERSION_PATCH})
