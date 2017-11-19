from ..detail.setup import GLM_MESSAGES, GLM_MESSAGES_ENABLED, defined, message, pyglmCompareType
from ..detail.func_exponential import *
from ..detail.func_vector_relational import lessThanEqual, lessThan
from ..detail.func_common import clamp, mix
from ..detail.type_vec3 import tvec3
from ..detail.type_vec4 import tvec4

if GLM_MESSAGES == GLM_MESSAGES_ENABLED and  not defined("GLM_EXT_INCLUDED"):
    message("GLM: GLM_GTC_color_space extension included")


def compute_rgbToSrgb(ColorRGB, GammaCorrection):
    if pyglmCompareType(ColorRGB, tvec4):
        return tvec4(compute_rgbToSrgb(tvec3(ColorRGB), GammaCorrection), ColorRGB.w)
    ClampedColor = ColorRGB.__class__(clamp(ColorRGB, 0, 1))

    return mix(pow(ClampedColor, ColorRGB.__class__(GammaCorrection)) * 1.055 - 0.055,
               ClampedColor * 12.92,
               lessThan(ClampedColor, ColorRGB.__class__(0.0031308)))

def compute_srgbToRgb(ColorSRGB, Gamma):
    if pyglmCompareType(ColorSRGB, tvec4):
        return tvec4(compute_srgbToRgb(tvec3(ColorSRGB), Gamma), ColorSRGB.w)
    return mix(pow((ColorSRGB + (0.055)) * (0.94786729857819905213270142180095), ColorSRGB.__class__(Gamma)),
                ColorSRGB * (0.07739938080495356037151702786378),
                lessThanEqual(ColorSRGB, ColorSRGB.__class__((0.04045))))

def convertLinearToSRGB(ColorSRGB, Gamma = None):
    if Gamma:
        return compute_srgbToRgb(ColorSRGB, (1.) / Gamma)
    return compute_srgbToRgb(ColorSRGB, (0.41666))

def convertSRGBToLinear(ColorSRGB, Gamma = None):
    if Gamma:
        return compute_srgbToRgb(ColorSRGB, Gamma)
    return compute_srgbToRgb(ColorSRGB, (2.4))
