try:
    from ._plant import *

except ImportError as e:
    raise ImportError(f"Failed to import plant: {e}")

# Make submodules available for direct import
import sys
sys.modules['plant.math'] = math
sys.modules['plant.sensors'] = sensors
sys.modules['plant.transforms'] = transforms
sys.modules['plant.types'] = types

# Metadata
__version__ = "0.0.1"
__author__ = "Anthony Gardner"
__license__ = "MIT"
