// define the dictionary
$.i18n().load( {
    'fr' : {
      "plus": "Plus",
      "moins": "Moins",
    },
    'en': {
      "plus": "Plus",
      "moins" : "Minus",
    }
})

// set the locale
$.i18n( {
    locale: 'en'
    //locale : navigator.language
} );


const modelInteger1 = new ModelInteger();
const modelInteger2 = new ModelInteger();

const controler = new Controler(modelInteger1, modelInteger2);
